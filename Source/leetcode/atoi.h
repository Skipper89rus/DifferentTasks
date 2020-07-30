#pragma once
#include <string>
#include <cassert>

using namespace std;

class Solution
{
public:
   int myAtoi(const string& str)
   {
      size_t idx = 0;
      skipWhitespace(str, idx);
      if (idx >= str.size())
         return 0;

      const int sign = getSign(str, idx);

      int res = 0;
      while (str[idx] >= '0' && str[idx] <= '9')
      {
         if (isNotInBounds(res, getDigit(str[idx])))
         {
            if (sign == 1)
               return INT_MAX;
            else
               return INT_MIN;
         }
         res = 10 * res + getDigit(str[idx++]);
      }
      return res * sign;
   }

private:
   void skipWhitespace(const string& str, size_t& idx)
   {
      while (idx < str.size() && str[idx] == ' ')
         idx++;
   }

   int getSign(const string& str, size_t& idx)
   {
      assert(idx < str.size());

      int sign = str[idx] == '-' ? -1 : 1;
      if (str[idx] == '-' || str[idx] == '+')
         idx++;
      return sign;
   }

   int getDigit(const char c)
   {
      return c - '0';
   }

   bool isNotInBounds(int val, int newDigit)
   {
      const int maxWithoutLast = INT_MAX / 10;
      const int maxLast = INT_MAX % 10;
      return val > maxWithoutLast || (val == maxWithoutLast && newDigit > maxLast);
   }
};