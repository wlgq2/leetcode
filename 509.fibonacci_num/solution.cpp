 class Solution 
 {
 public:
     int fib(int n) 
     {
         int pre1 = 0;
         int pre2 = 0;
         int current = 0;
         for (int i = 0;i < n;i++)
         {
             current = pre1 + pre2;
             if (current == 0)
                 current = 1;
             pre1 = pre2;
             pre2 = current;
         }
         return current;
     }
 };
