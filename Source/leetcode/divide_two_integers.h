#pragma once

#include <iostream>
#include <cmath>

class Solution
{
public:
   int divide(long long dividend, long long divisor)
   {
      // Calculate sign of divisor i.e., sign will be negative only if either one of them is negative, otherwise it will be positive
      int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
      if (dividend == INT_MAX && abs(divisor) == 1)
         return divisor > 0 ? INT_MAX : INT_MIN;
      if (dividend == INT_MIN && abs(divisor) == 1)
         return divisor > 0 ? INT_MIN : INT_MAX;

      // Update both divisor and dividend positive
      dividend = abs(dividend);
      divisor = abs(divisor);

      long long quotient = 0, temp = 0;

      // Test down from the highest bit and accumulate the tentative value for valid bit
      for (int i = 31; i >= 0; --i)
      {
         if (temp + (divisor << i) <= dividend)
         {
            temp += divisor << i;
            quotient |= 1LL << i;
         }
      }
      return sign * quotient;
   }
};

// DEBUG ZONE
inline bool run_test()
{
   std::cout << Solution().divide(10, 3) << std::endl;
   std::cout << Solution().divide(-2147483648, 2) << std::endl;
   std::cout << Solution().divide(2147483647, 2) << std::endl;
   std::cout << Solution().divide(-2147483648, 1) << std::endl;
   std::cout << Solution().divide(2147483647, 1) << std::endl;
   std::cout << Solution().divide(-2147483648, -1) << std::endl;
   std::cout << Solution().divide(2147483647, -1) << std::endl;
   return true;
}