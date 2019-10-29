#include <foo/footils.h>
#include <gtest/gtest.h>
#include <ros/ros.h>


TEST(TestFootils, checkString) {
  std::string in("_hello_");
  std::string out("foo_hello_foo");
  EXPECT_EQ(foo::foofy(in), out);
}


TEST(TestFootils, checkStringMsg) {
  std_msgs::String in, out;
  in.data = "_hello_";
  out.data = "foo_hello_foo";
  EXPECT_EQ(foo::foofy(in).data, out.data);
}


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "footils_test");
  return RUN_ALL_TESTS();
}
