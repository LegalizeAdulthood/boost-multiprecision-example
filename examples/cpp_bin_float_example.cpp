#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/math/special_functions/gamma.hpp>

#include <iostream>

int main()
{
   using namespace boost::multiprecision;

   // Operations at fixed precision and full numeric_limits support:
   cpp_bin_float_100 b = 2;
   std::cout << std::numeric_limits<cpp_bin_float_100>::digits << std::endl;
   std::cout << std::numeric_limits<cpp_bin_float_100>::digits10 << std::endl;

   // We can use any C++ std lib function, lets print all the digits as well:
   std::cout << std::setprecision(std::numeric_limits<cpp_bin_float_100>::max_digits10)
      << log(b) << std::endl; // print log(2)

   // We can also use any function from Boost.Math:
   std::cout << boost::math::tgamma(b) << std::endl;
   // These even work when the argument is an expression template:
   std::cout << boost::math::tgamma(b * b) << std::endl;

   // And since we have an extended exponent range we can generate some really large
   // numbers here (4.0238726007709377354370243e+2564):
   std::cout << boost::math::tgamma(cpp_bin_float_100(1000)) << std::endl;
   return 0;
}
