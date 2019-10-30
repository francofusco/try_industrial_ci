#include "sequences/sequences.h"

namespace sequences {

unsigned int collatz(unsigned int n) {
  return n%2==0 ? n/2 : 3*n+1;
}

}
