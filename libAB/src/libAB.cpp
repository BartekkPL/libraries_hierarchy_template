#include "libAB.hpp"

#include <lib_a/libA.hpp>
#include <lib_b/libB.hpp>

std::string LibAB::getAB() noexcept {
  return {LibA::getA(), LibB::getB()};
}
