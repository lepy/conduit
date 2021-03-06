// Copyright (c) Lawrence Livermore National Security, LLC and other Conduit
// Project developers. See top-level LICENSE AND COPYRIGHT files for dates and
// other details. No copyright assignment is required to contribute to Conduit.

//-----------------------------------------------------------------------------
///
/// file: conduit_node_to_value.cpp
///
//-----------------------------------------------------------------------------

#include "conduit.hpp"

#include "gtest/gtest.h"

using namespace conduit;

//-----------------------------------------------------------------------------
TEST(conduit_node_to_value, string_to_scalar)
{
    Node n;
    n.set("127");
    
    EXPECT_EQ( n.to_uint8(),127);
    EXPECT_EQ( n.to_uint16(),127);
    EXPECT_EQ( n.to_uint32(),127);
    EXPECT_EQ( n.to_uint64(),127);

    EXPECT_EQ( n.to_int8(),127);
    EXPECT_EQ( n.to_int16(),127);
    EXPECT_EQ( n.to_int32(),127);
    EXPECT_EQ( n.to_int64(),127);

    EXPECT_NEAR( n.to_float32(),127,0.0001);
    EXPECT_NEAR( n.to_float64(),127,0.0001);

    EXPECT_EQ( n.to_char(),127);
    EXPECT_EQ( n.to_short(),127);
    EXPECT_EQ( n.to_int(),127);
    EXPECT_EQ( n.to_long(),127);

    EXPECT_EQ( n.to_signed_char(),127);
    EXPECT_EQ( n.to_signed_short(),127);
    EXPECT_EQ( n.to_signed_int(),127);
    EXPECT_EQ( n.to_signed_long(),127);

    EXPECT_EQ( n.to_unsigned_char(),127);
    EXPECT_EQ( n.to_unsigned_short(),127);
    EXPECT_EQ( n.to_unsigned_int(),127);
    EXPECT_EQ( n.to_unsigned_long(),127);

    
    EXPECT_NEAR( n.to_float(),127,0.0001);
    EXPECT_NEAR( n.to_double(),127,0.0001);
}


//-----------------------------------------------------------------------------
TEST(conduit_node_to_value, uint8_to_scalar)
{
    Node n;
    n.set_uint8(127);
    
    EXPECT_EQ( n.to_uint8(),127);
    EXPECT_EQ( n.to_uint16(),127);
    EXPECT_EQ( n.to_uint32(),127);
    EXPECT_EQ( n.to_uint64(),127);

    EXPECT_EQ( n.to_int8(),127);
    EXPECT_EQ( n.to_int16(),127);
    EXPECT_EQ( n.to_int32(),127);
    EXPECT_EQ( n.to_int64(),127);

    EXPECT_NEAR( n.to_float32(),127,0.0001);
    EXPECT_NEAR( n.to_float64(),127,0.0001);

    EXPECT_EQ( n.to_unsigned_char(),127);
    EXPECT_EQ( n.to_unsigned_short(),127);
    EXPECT_EQ( n.to_unsigned_int(),127);
    EXPECT_EQ( n.to_unsigned_long(),127);

    EXPECT_EQ( n.to_char(),127);
    EXPECT_EQ( n.to_short(),127);
    EXPECT_EQ( n.to_int(),127);
    EXPECT_EQ( n.to_long(),127);
    
    EXPECT_NEAR( n.to_float(),127,0.0001);
    EXPECT_NEAR( n.to_double(),127,0.0001);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_to_value, uint16_to_scalar)
{
    Node n;
    n.set_uint16(127);
    
    EXPECT_EQ( n.to_uint8(),127);
    EXPECT_EQ( n.to_uint16(),127);
    EXPECT_EQ( n.to_uint32(),127);
    EXPECT_EQ( n.to_uint64(),127);

    EXPECT_EQ( n.to_int8(),127);
    EXPECT_EQ( n.to_int16(),127);
    EXPECT_EQ( n.to_int32(),127);
    EXPECT_EQ( n.to_int64(),127);

    EXPECT_NEAR( n.to_float32(),127,0.0001);
    EXPECT_NEAR( n.to_float64(),127,0.0001);

    EXPECT_EQ( n.to_unsigned_char(),127);
    EXPECT_EQ( n.to_unsigned_short(),127);
    EXPECT_EQ( n.to_unsigned_int(),127);
    EXPECT_EQ( n.to_unsigned_long(),127);

    EXPECT_EQ( n.to_char(),127);
    EXPECT_EQ( n.to_short(),127);
    EXPECT_EQ( n.to_int(),127);
    EXPECT_EQ( n.to_long(),127);
    
    EXPECT_NEAR( n.to_float(),127,0.0001);
    EXPECT_NEAR( n.to_double(),127,0.0001);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_to_value, uint32_to_scalar)
{
    Node n;
    n.set_uint32(127);
    
    EXPECT_EQ( n.to_uint8(),127);
    EXPECT_EQ( n.to_uint16(),127);
    EXPECT_EQ( n.to_uint32(),127);
    EXPECT_EQ( n.to_uint64(),127);

    EXPECT_EQ( n.to_int8(),127);
    EXPECT_EQ( n.to_int16(),127);
    EXPECT_EQ( n.to_int32(),127);
    EXPECT_EQ( n.to_int64(),127);

    EXPECT_NEAR( n.to_float32(),127,0.0001);
    EXPECT_NEAR( n.to_float64(),127,0.0001);

    EXPECT_EQ( n.to_unsigned_char(),127);
    EXPECT_EQ( n.to_unsigned_short(),127);
    EXPECT_EQ( n.to_unsigned_int(),127);
    EXPECT_EQ( n.to_unsigned_long(),127);

    EXPECT_EQ( n.to_char(),127);
    EXPECT_EQ( n.to_short(),127);
    EXPECT_EQ( n.to_int(),127);
    EXPECT_EQ( n.to_long(),127);
    
    EXPECT_NEAR( n.to_float(),127,0.0001);
    EXPECT_NEAR( n.to_double(),127,0.0001);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_to_value, uint64_to_scalar)
{
    Node n;
    n.set_uint64(127);
    
    EXPECT_EQ( n.to_uint8(),127);
    EXPECT_EQ( n.to_uint16(),127);
    EXPECT_EQ( n.to_uint32(),127);
    EXPECT_EQ( n.to_uint64(),127);

    EXPECT_EQ( n.to_int8(),127);
    EXPECT_EQ( n.to_int16(),127);
    EXPECT_EQ( n.to_int32(),127);
    EXPECT_EQ( n.to_int64(),127);

    EXPECT_NEAR( n.to_float32(),127,0.0001);
    EXPECT_NEAR( n.to_float64(),127,0.0001);

    EXPECT_EQ( n.to_unsigned_char(),127);
    EXPECT_EQ( n.to_unsigned_short(),127);
    EXPECT_EQ( n.to_unsigned_int(),127);
    EXPECT_EQ( n.to_unsigned_long(),127);

    EXPECT_EQ( n.to_char(),127);
    EXPECT_EQ( n.to_short(),127);
    EXPECT_EQ( n.to_int(),127);
    EXPECT_EQ( n.to_long(),127);
    
    EXPECT_NEAR( n.to_float(),127,0.0001);
    EXPECT_NEAR( n.to_double(),127,0.0001);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_to_value, int8_to_scalar)
{
    Node n;
    n.set_int8(127);
    
    EXPECT_EQ( n.to_uint8(),127);
    EXPECT_EQ( n.to_uint16(),127);
    EXPECT_EQ( n.to_uint32(),127);
    EXPECT_EQ( n.to_uint64(),127);

    EXPECT_EQ( n.to_int8(),127);
    EXPECT_EQ( n.to_int16(),127);
    EXPECT_EQ( n.to_int32(),127);
    EXPECT_EQ( n.to_int64(),127);

    EXPECT_NEAR( n.to_float32(),127,0.0001);
    EXPECT_NEAR( n.to_float64(),127,0.0001);

    EXPECT_EQ( n.to_unsigned_char(),127);
    EXPECT_EQ( n.to_unsigned_short(),127);
    EXPECT_EQ( n.to_unsigned_int(),127);
    EXPECT_EQ( n.to_unsigned_long(),127);

    EXPECT_EQ( n.to_char(),127);
    EXPECT_EQ( n.to_short(),127);
    EXPECT_EQ( n.to_int(),127);
    EXPECT_EQ( n.to_long(),127);
    
    EXPECT_NEAR( n.to_float(),127,0.0001);
    EXPECT_NEAR( n.to_double(),127,0.0001);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_to_value, int16_to_scalar)
{
    Node n;
    n.set_int16(127);
    
    EXPECT_EQ( n.to_uint8(),127);
    EXPECT_EQ( n.to_uint16(),127);
    EXPECT_EQ( n.to_uint32(),127);
    EXPECT_EQ( n.to_uint64(),127);

    EXPECT_EQ( n.to_int8(),127);
    EXPECT_EQ( n.to_int16(),127);
    EXPECT_EQ( n.to_int32(),127);
    EXPECT_EQ( n.to_int64(),127);

    EXPECT_NEAR( n.to_float32(),127,0.0001);
    EXPECT_NEAR( n.to_float64(),127,0.0001);

    EXPECT_EQ( n.to_unsigned_char(),127);
    EXPECT_EQ( n.to_unsigned_short(),127);
    EXPECT_EQ( n.to_unsigned_int(),127);
    EXPECT_EQ( n.to_unsigned_long(),127);

    EXPECT_EQ( n.to_char(),127);
    EXPECT_EQ( n.to_short(),127);
    EXPECT_EQ( n.to_int(),127);
    EXPECT_EQ( n.to_long(),127);
    
    EXPECT_NEAR( n.to_float(),127,0.0001);
    EXPECT_NEAR( n.to_double(),127,0.0001);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_to_value, int32_to_scalar)
{
    Node n;
    n.set_int32(127);
    
    EXPECT_EQ( n.to_uint8(),127);
    EXPECT_EQ( n.to_uint16(),127);
    EXPECT_EQ( n.to_uint32(),127);
    EXPECT_EQ( n.to_uint64(),127);

    EXPECT_EQ( n.to_int8(),127);
    EXPECT_EQ( n.to_int16(),127);
    EXPECT_EQ( n.to_int32(),127);
    EXPECT_EQ( n.to_int64(),127);

    EXPECT_NEAR( n.to_float32(),127,0.0001);
    EXPECT_NEAR( n.to_float64(),127,0.0001);

    EXPECT_EQ( n.to_unsigned_char(),127);
    EXPECT_EQ( n.to_unsigned_short(),127);
    EXPECT_EQ( n.to_unsigned_int(),127);
    EXPECT_EQ( n.to_unsigned_long(),127);

    EXPECT_EQ( n.to_char(),127);
    EXPECT_EQ( n.to_short(),127);
    EXPECT_EQ( n.to_int(),127);
    EXPECT_EQ( n.to_long(),127);
    
    EXPECT_NEAR( n.to_float(),127,0.0001);
    EXPECT_NEAR( n.to_double(),127,0.0001);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_to_value, int64_to_scalar)
{
    Node n;
    n.set_int64(127);
    
    EXPECT_EQ( n.to_uint8(),127);
    EXPECT_EQ( n.to_uint16(),127);
    EXPECT_EQ( n.to_uint32(),127);
    EXPECT_EQ( n.to_uint64(),127);

    EXPECT_EQ( n.to_int8(),127);
    EXPECT_EQ( n.to_int16(),127);
    EXPECT_EQ( n.to_int32(),127);
    EXPECT_EQ( n.to_int64(),127);

    EXPECT_NEAR( n.to_float32(),127,0.0001);
    EXPECT_NEAR( n.to_float64(),127,0.0001);

    EXPECT_EQ( n.to_unsigned_char(),127);
    EXPECT_EQ( n.to_unsigned_short(),127);
    EXPECT_EQ( n.to_unsigned_int(),127);
    EXPECT_EQ( n.to_unsigned_long(),127);

    EXPECT_EQ( n.to_char(),127);
    EXPECT_EQ( n.to_short(),127);
    EXPECT_EQ( n.to_int(),127);
    EXPECT_EQ( n.to_long(),127);
    
    EXPECT_NEAR( n.to_float(),127,0.0001);
    EXPECT_NEAR( n.to_double(),127,0.0001);
}


//-----------------------------------------------------------------------------
TEST(conduit_node_to_value, float32_to_scalar)
{
    Node n;
    n.set_float32(127);
    
    EXPECT_EQ( n.to_uint8(),127);
    EXPECT_EQ( n.to_uint16(),127);
    EXPECT_EQ( n.to_uint32(),127);
    EXPECT_EQ( n.to_uint64(),127);

    EXPECT_EQ( n.to_int8(),127);
    EXPECT_EQ( n.to_int16(),127);
    EXPECT_EQ( n.to_int32(),127);
    EXPECT_EQ( n.to_int64(),127);

    EXPECT_NEAR( n.to_float32(),127,0.0001);
    EXPECT_NEAR( n.to_float64(),127,0.0001);

    EXPECT_EQ( n.to_unsigned_char(),127);
    EXPECT_EQ( n.to_unsigned_short(),127);
    EXPECT_EQ( n.to_unsigned_int(),127);
    EXPECT_EQ( n.to_unsigned_long(),127);

    EXPECT_EQ( n.to_char(),127);
    EXPECT_EQ( n.to_short(),127);
    EXPECT_EQ( n.to_int(),127);
    EXPECT_EQ( n.to_long(),127);
    
    EXPECT_NEAR( n.to_float(),127,0.0001);
    EXPECT_NEAR( n.to_double(),127,0.0001);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_to_value, float64_to_scalar)
{
    Node n;
    n.set_float64(127);
    
    EXPECT_EQ( n.to_uint8(),127);
    EXPECT_EQ( n.to_uint16(),127);
    EXPECT_EQ( n.to_uint32(),127);
    EXPECT_EQ( n.to_uint64(),127);

    EXPECT_EQ( n.to_int8(),127);
    EXPECT_EQ( n.to_int16(),127);
    EXPECT_EQ( n.to_int32(),127);
    EXPECT_EQ( n.to_int64(),127);

    EXPECT_NEAR( n.to_float32(),127,0.0001);
    EXPECT_NEAR( n.to_float64(),127,0.0001);

    EXPECT_EQ( n.to_unsigned_char(),127);
    EXPECT_EQ( n.to_unsigned_short(),127);
    EXPECT_EQ( n.to_unsigned_int(),127);
    EXPECT_EQ( n.to_unsigned_long(),127);

    EXPECT_EQ( n.to_char(),127);
    EXPECT_EQ( n.to_short(),127);
    EXPECT_EQ( n.to_int(),127);
    EXPECT_EQ( n.to_long(),127);
    
    EXPECT_NEAR( n.to_float(),127,0.0001);
    EXPECT_NEAR( n.to_double(),127,0.0001);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_to_value, data_type_to_scalar)
{
    const DataType::TypeID leaf_tids[10] = {
        DataType::INT8_ID, DataType::INT16_ID, DataType::INT32_ID, DataType::INT64_ID,
        DataType::UINT8_ID, DataType::UINT16_ID, DataType::UINT32_ID, DataType::UINT64_ID,
        DataType::FLOAT32_ID, DataType::FLOAT64_ID
    };

    for(index_t ti = 0; ti < 10; ti++)
    {
        Node base_node;
        const DataType::TypeID base_tid = leaf_tids[ti];
        {
            Node temp;
            temp.set(127);
            temp.to_data_type(base_tid, base_node);
        }

        for(index_t tj = 0; tj < 10; tj++)
        {
            Node to_node;
            const DataType::TypeID to_tid = leaf_tids[tj];
            base_node.to_data_type(to_tid, to_node);

            EXPECT_EQ(to_node.dtype().id(), to_tid);
            switch(to_tid)
            {
                /// ints ///
                case DataType::INT8_ID:
                {
                    EXPECT_EQ(to_node.as_int8(),127);
                    break;
                }
                case DataType::INT16_ID:
                {
                    EXPECT_EQ(to_node.as_int16(),127);
                    break;
                }
                case DataType::INT32_ID:
                {
                    EXPECT_EQ(to_node.as_int32(),127);
                    break;
                }
                case DataType::INT64_ID:
                {
                    EXPECT_EQ(to_node.as_int64(),127);
                    break;
                }
                /// uints ///
                case DataType::UINT8_ID:
                {
                    EXPECT_EQ(to_node.as_uint8(),127);
                    break;
                }
                case DataType::UINT16_ID:
                {
                    EXPECT_EQ(to_node.as_uint16(),127);
                    break;
                }
                case DataType::UINT32_ID:
                {
                    EXPECT_EQ(to_node.as_uint32(),127);
                    break;
                }
                case DataType::UINT64_ID:
                {
                    EXPECT_EQ(to_node.as_uint64(),127);
                    break;
                }
                /// floats ///
                case DataType::FLOAT32_ID:
                {
                    EXPECT_NEAR(to_node.as_float32(),127.0,1e-4);
                    break;
                }
                case DataType::FLOAT64_ID:
                {
                    EXPECT_NEAR(to_node.as_float64(),127.0,1e-4);
                    break;
                }
                case DataType::CHAR8_STR_ID:
                {
                    EXPECT_EQ(to_node.to_json(),"127");
                }
                case DataType::EMPTY_ID:
                {
                    // no conversion to test
                    break;
                }
                case DataType::LIST_ID:
                {
                    // no conversion to test
                    break;
                }
                case DataType::OBJECT_ID:
                {
                    // no conversion to test
                    break;
                }
            }
        }
    }
}

//-----------------------------------------------------------------------------
// check default values from as_zzz, by avoiding exceptions on warn
//----------------------------------------------------------------------------- 

//-----------------------------------------------------------------------------
void 
print_msg(const std::string &msg,
          const std::string &file,
          int line)
{
    std::cout << "File:"    << file << std::endl;
    std::cout << "Line:"    << line << std::endl;
    std::cout << "Message:" << msg  << std::endl;
}

//-----------------------------------------------------------------------------
void 
my_warning_handler(const std::string &msg,
                   const std::string &file,
                   int line)
{
    print_msg(msg,file,line);
}

//-----------------------------------------------------------------------------
TEST(conduit_node_set, get_from_empty)
{
    // override warning handler so we can check the default
    // return values on dtype mismatch
    conduit::utils::set_warning_handler(my_warning_handler);
    
    Node n;// empty

    // bw-style types (pointers)
    int8     *int8_ptr    = n.value();
    int16    *int16_ptr   = n.value();
    int32    *int32_ptr   = n.value();
    int64    *int64_ptr   = n.value();
    
    uint8     *uint8_ptr    = n.value();
    uint16    *uint16_ptr   = n.value();
    uint32    *uint32_ptr   = n.value();
    uint64    *uint64_ptr   = n.value();
    
    float32  *float32_ptr = n.value();
    float64  *float64_ptr = n.value();

    EXPECT_TRUE(int8_ptr == NULL);
    EXPECT_TRUE(int16_ptr == NULL);
    EXPECT_TRUE(int32_ptr == NULL);
    EXPECT_TRUE(int64_ptr == NULL);

    EXPECT_TRUE(uint8_ptr == NULL);
    EXPECT_TRUE(uint16_ptr == NULL);
    EXPECT_TRUE(uint32_ptr == NULL);
    EXPECT_TRUE(uint64_ptr == NULL);
    
    EXPECT_TRUE(float32_ptr == NULL);
    EXPECT_TRUE(float64_ptr == NULL);

    // bw-style types (scalars)

    int8  int8_val  = n.value();
    int16 int16_val = n.value();
    int32 int32_val = n.value();
    int64 int64_val = n.value();

    uint8  uint8_val  = n.value();
    uint16 uint16_val = n.value();
    uint32 uint32_val = n.value();
    uint64 uint64_val = n.value();
    
    float32 float32_val = n.value();
    float64 float64_val = n.value();
    
    EXPECT_EQ(int8_val,0);
    EXPECT_EQ(int16_val,0);
    EXPECT_EQ(int32_val,0);
    EXPECT_EQ(int64_val,0);

    EXPECT_EQ(uint8_val,0);
    EXPECT_EQ(uint16_val,0);
    EXPECT_EQ(uint32_val,0);
    EXPECT_EQ(uint64_val,0);

    EXPECT_EQ(float32_val,0);
    EXPECT_EQ(float64_val,0);

    // c native types (pointers)
    char   *char_ptr   = n.value();
    short  *short_ptr  = n.value();
    int    *int_ptr    = n.value();
    long   *long_ptr   = n.value();

    signed char   *schar_ptr  = n.value();
    signed short  *sshort_ptr = n.value();
    signed int    *sint_ptr   = n.value();
    signed long   *slong_ptr  = n.value();


    unsigned char   *uchar_ptr  = n.value();
    unsigned short  *ushort_ptr = n.value();
    unsigned int    *uint_ptr   = n.value();
    unsigned long   *ulong_ptr  = n.value();

    float  *float_ptr  = n.value();
    double *double_ptr = n.value();

    EXPECT_TRUE(char_ptr == NULL);
    EXPECT_TRUE(short_ptr == NULL);
    EXPECT_TRUE(int_ptr == NULL);
    EXPECT_TRUE(long_ptr == NULL);

    EXPECT_TRUE(schar_ptr == NULL);
    EXPECT_TRUE(sshort_ptr == NULL);
    EXPECT_TRUE(sint_ptr == NULL);
    EXPECT_TRUE(slong_ptr == NULL);

    EXPECT_TRUE(uchar_ptr == NULL);
    EXPECT_TRUE(ushort_ptr == NULL);
    EXPECT_TRUE(uint_ptr == NULL);
    EXPECT_TRUE(ulong_ptr == NULL);
    
    EXPECT_TRUE(float_ptr == NULL);
    EXPECT_TRUE(double_ptr == NULL);
    
    // c native types (scalars)
    char   char_val  = n.value();
    short  short_val = n.value();
    int    int_val   = n.value();
    long   long_val  = n.value();

    signed char   schar_val  = n.value();
    signed short  sshort_val = n.value();
    signed int    sint_val   = n.value();
    signed long   slong_val  = n.value();


    unsigned char   uchar_val  = n.value();
    unsigned short  ushort_val = n.value();
    unsigned int    uint_val   = n.value();
    unsigned long   ulong_val  = n.value();
    
    float  float_val  = n.value();
    double double_val = n.value();

    EXPECT_EQ(char_val,0);
    EXPECT_EQ(short_val,0);
    EXPECT_EQ(int_val,0);
    EXPECT_EQ(long_val,0);

    EXPECT_EQ(schar_val,0);
    EXPECT_EQ(sshort_val,0);
    EXPECT_EQ(sint_val,0);
    EXPECT_EQ(slong_val,0);

    EXPECT_EQ(uchar_val,0);
    EXPECT_EQ(ushort_val,0);
    EXPECT_EQ(uint_val,0);
    EXPECT_EQ(ulong_val,0);
    
    EXPECT_EQ(float_val,0);
    EXPECT_EQ(double_val,0);

    // reset warning handler to default
    conduit::utils::set_warning_handler(conduit::utils::default_warning_handler);
}



