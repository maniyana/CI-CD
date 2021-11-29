#include <gtest/gtest.h>

// Since the software we're testing is C code, and gtest is a C++ library, we
// need to extern our C functions in order for the compiler to use them.
extern "C"
{
#include <misc/reg_map.h>
}

// Demonstrate some basic assertions.
TEST(RegMapTest, SetGetConfig)
{
  uint8 data = 42;
  uint32 offset = 0;

  // Set the data
  AurixSetConfig(offset, sizeof(data), &data);

  // Read the result back
  uint8 buffer;

  AurixGetConfig(offset, sizeof(data), &buffer);

  // Ensure that when we read the config back, we get the same
  // value.
  EXPECT_EQ(data, buffer);
}
