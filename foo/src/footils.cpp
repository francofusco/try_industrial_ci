#include "foo/footils.h"

namespace foo {


std::string foofy(const std::string& s) {
  return "foo" + s + "foo";
}

std_msgs::String foofy(const std_msgs::String& s) {
  std_msgs::String r;
  r.data = foofy(s.data);
  return r;
}


}
