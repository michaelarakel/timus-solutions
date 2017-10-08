#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main ()
{
   const long long base = 32;
   long long n;
   cin >> n;
   const long long mod = 7123451;
   vector < long long> p;
   p.push_back(1);
   for (size_t i = 1; i <= 2 * n; i++)
      p.push_back((523 * p[i - 1]) % mod);      
   string s, t;
   getline (cin, s);
   getline (cin, s);
   getline (cin, t);
   s += s;
   vector < long long> hash_s(2*n + 1);
   long long hash_t = 0;
   long long h_temp1 = (s[0] - base), h_temp2 = t[0] - base;
   hash_s[0] = 0;
   hash_s[1] = h_temp1;
   hash_t += h_temp2;

   for (size_t i = 1; i < 2 * n; i++)
   {
      hash_s[i + 1] = (hash_s[i] + (s[i] - base) * p[i]) % mod;      
      if (i < n)
      {
         hash_t += ((t[i] - base) * p[i]);
         hash_t %= mod;
      }
   }
   long long ans = -1;
   for (size_t i = 0; i < n; i++)
      if (hash_s[i + t.size()] == (hash_s[i] + p[i] * hash_t) % mod)
      {
         if (i != 0)
            ans = n - i;
         else
            ans = 0;
         break;
      }
   cout << ans;
}