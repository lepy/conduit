// Copyright (c) Lawrence Livermore National Security, LLC and other Conduit
// Project developers. See top-level LICENSE AND COPYRIGHT files for dates and
// other details. No copyright assignment is required to contribute to Conduit.

//-----------------------------------------------------------------------------
///
/// file: t_relay_zfp.cpp
///
//-----------------------------------------------------------------------------

#include "conduit_relay.hpp"
#include "conduit_relay_zfp.hpp"
#include "gtest/gtest.h"
#include <cstring>

using namespace conduit;
using namespace conduit::relay;

//-----------------------------------------------------------------------------
TEST(conduit_relay_zfp, wrap_zfparray_and_verify_header)
{
    // initialize empty result Node
    Node result;
    EXPECT_FALSE(result.has_child(io::ZFP_HEADER_FIELD_NAME));

    // create compressed-array
    uint nx = 9;
    uint ny = 12;
    double rate = 8.0;
    zfp::array2f arr(nx, ny, rate);

    // write zfparray to Node
    EXPECT_EQ(0, io::wrap_zfparray(&arr, result));

    // verify header entry was set
    EXPECT_TRUE(result.has_child(io::ZFP_HEADER_FIELD_NAME));
    Node n_header = result[io::ZFP_HEADER_FIELD_NAME];

    // assert header dtype
    EXPECT_TRUE(n_header.dtype().is_uint8());
    uint8_array header_as_arr = n_header.as_uint8_array();

    // assert header length
    zfp::array::header header = arr.get_header();
    EXPECT_EQ(sizeof(header), header_as_arr.number_of_elements());

    // assert header contents
    EXPECT_TRUE(0 == std::memcmp(header.buffer, n_header.data_ptr(), sizeof(header)));
}

//-----------------------------------------------------------------------------
TEST(conduit_relay_zfp, wrap_zfparray_and_verify_compressed_data)
{
    // initialize empty result Node
    Node result;
    EXPECT_FALSE(result.has_child(io::ZFP_COMPRESSED_DATA_FIELD_NAME));

    // create compressed-array
    uint nx = 9;
    uint ny = 12;
    uint ntotal = nx * ny;
    float * vals = new float[ntotal];
    uint i;
    for (i = 0; i < ntotal; i++) {
        vals[i] = i*i;
    }

    double rate = 8.0;
    zfp::array2f arr(nx, ny, rate, vals);

    // write zfparray to Node
    EXPECT_EQ(0, io::wrap_zfparray(&arr, result));

    // verify compressed data entry was set
    EXPECT_TRUE(result.has_child(io::ZFP_COMPRESSED_DATA_FIELD_NAME));
    Node n_data = result[io::ZFP_COMPRESSED_DATA_FIELD_NAME];

    EXPECT_TRUE(n_data.dtype().is_unsigned_integer());
    size_t compressed_data_num_words = arr.compressed_size() * CHAR_BIT / stream_word_bits;

    // compressed-data entry written with same uint type, having width `stream_word_bits`
    switch(stream_word_bits) {
        case 64:
            EXPECT_TRUE(n_data.dtype().is_uint64());
            {
                uint64_array data_as_arr = n_data.as_uint64_array();
                EXPECT_EQ(compressed_data_num_words, data_as_arr.number_of_elements());
            }
            break;

        case 32:
            EXPECT_TRUE(n_data.dtype().is_uint32());
            {
                uint32_array data_as_arr = n_data.as_uint32_array();
                EXPECT_EQ(compressed_data_num_words, data_as_arr.number_of_elements());
            }
            break;

        case 16:
            EXPECT_TRUE(n_data.dtype().is_uint16());
            {
                uint16_array data_as_arr = n_data.as_uint16_array();
                EXPECT_EQ(compressed_data_num_words, data_as_arr.number_of_elements());
            }
            break;

        case 8:
            EXPECT_TRUE(n_data.dtype().is_uint8());
            {
                uint8_array data_as_arr = n_data.as_uint8_array();
                EXPECT_EQ(compressed_data_num_words, data_as_arr.number_of_elements());
            }
            break;

        default:
            FAIL() << "ZFP was compiled with an unrecognizable word type";
            break;
    }

    delete [] vals;

    EXPECT_TRUE(0 == std::memcmp(arr.compressed_data(), n_data.data_ptr(), arr.compressed_size()));
}

//-----------------------------------------------------------------------------
TEST(conduit_relay_zfp, wrap_zfparray_with_header_exception)
{
    // create compressed-array that does not support short header
    uint nx = 9;
    uint ny = 12;
    uint nz = 5;
    double rate = 64.0;
    zfp::array3d arr(nx, ny, nz, rate);

    // write zfparray to Node, but expect failure
    Node result;
    EXPECT_EQ(1, io::wrap_zfparray(&arr, result));
}

//-----------------------------------------------------------------------------
TEST(conduit_relay_zfp, unwrap_zfparray)
{
    // create compressed-array
    uint nx = 9;
    uint ny = 12;

    float vals[nx * ny];
    uint i, j;
    for (j = 0; j < ny; j++) {
        for (i = 0; i < nx; i++) {
            vals[nx*j + i] = i * 10. + j*j;
        }
    }

    double rate = 32.0;
    zfp::array2f original_arr(nx, ny, rate, vals);

    // write zfparray to Node
    Node result;
    EXPECT_EQ(0, io::wrap_zfparray(&original_arr, result));

    // fetch zfparray object from Node
    zfp::array* fetched_arr = io::unwrap_zfparray(result);

    // verify against original_arr
    ASSERT_TRUE(fetched_arr != 0);

    zfp::array2f* casted_arr = dynamic_cast<zfp::array2f*>(fetched_arr);
    ASSERT_TRUE(casted_arr != 0);

    EXPECT_EQ(nx, casted_arr->size_x());
    EXPECT_EQ(ny, casted_arr->size_y());
    EXPECT_EQ(rate, casted_arr->rate());

    // verify compressed data
    EXPECT_EQ(original_arr.compressed_size(), casted_arr->compressed_size());
    EXPECT_TRUE(0 == std::memcmp(original_arr.compressed_data(), casted_arr->compressed_data(), original_arr.compressed_size()));

    delete fetched_arr;
}

//-----------------------------------------------------------------------------
TEST(conduit_relay_zfp, unwrap_zfparray_with_exception)
{
    // create compressed-array
    uint nx = 9;
    uint ny = 12;

    double rate = 32.0;
    zfp::array2f original_arr(nx, ny, rate);

    // write zfparray to Node
    Node result;
    EXPECT_EQ(0, io::wrap_zfparray(&original_arr, result));

    // corrupt the Node's data
    size_t n = 10;
    float * vals = new float[n];
    for (size_t i = 0; i < n; i++) {
        vals[i] = 0;
    }
    result[io::ZFP_HEADER_FIELD_NAME].set(vals, sizeof(vals));

    // fetch zfparray object from Node
    zfp::array* fetched_arr = io::unwrap_zfparray(result);

    // verify no instance returned
    ASSERT_TRUE(fetched_arr == 0);

    delete [] vals;
}

//-----------------------------------------------------------------------------
TEST(conduit_relay_zfp, unwrap_zfparray_with_compressed_data_dtype_mismatched_with_compiled_zfp_word_size)
{
    // create compressed-array
    uint nx = 9;
    uint ny = 12;
    uint nz = 15;

    double rate = 16.0;
    zfp::array3f arr(nx, ny, nz, rate);

    // write zfparray to Node
    Node result;
    EXPECT_EQ(0, relay::io::wrap_zfparray(&arr, result));

    // remove compressed-data node
    EXPECT_TRUE(result.has_child(io::ZFP_COMPRESSED_DATA_FIELD_NAME));
    result.remove(io::ZFP_COMPRESSED_DATA_FIELD_NAME);

    // re-add compressed-data node as the wrong type
    switch(stream_word_bits) {
        case 64:
        case 32:
        case 16:
            {
                conduit::uint8 data = 3;
                result[io::ZFP_COMPRESSED_DATA_FIELD_NAME] = data;
            }
            break;

        case 8:
            {
                conduit::uint64 data = 3;
                result[io::ZFP_COMPRESSED_DATA_FIELD_NAME] = data;
            }
            break;

        default:
            FAIL() << "ZFP was compiled with an unrecognizable word type";
    }

    // fetch zfparray object from Node
    zfp::array* fetched_arr = io::unwrap_zfparray(result);

    // verify no instance returned
    ASSERT_TRUE(fetched_arr == 0);
}

