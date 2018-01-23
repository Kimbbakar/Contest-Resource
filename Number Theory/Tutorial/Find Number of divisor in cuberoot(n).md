If we have a large number like 10^18, How could we find number of divisor of it ?

If we approach this problem with our as usual O(n^(1/2) ) solution , it bring TLE for us.

To solve this problem , there is a solution with O(n^(1/3)) complexity.

Lets express the number N = x * y

here , x <= n^(1/3) (for n=10^18, x = 10^6)

So for all x , we can count number of divisor via naive approach.

So if we consider f(x) = number of total divisor for all x.

for y , we can see that
 
 1) y = A prime
 2) y = Square of a prime
 3) y = Multiply of 2 prime

 y  cant have more than two prime factors at this step because factors left are already greater than 10^6 .

 So now
 if y is a prime number : F(Y) = 2.
 if y is square of a prime number : F(Y) = 3.
 if y is product of two distinct prime numbers : F(Y) = 4.

 So , f(N) = f (x) * f (y)

 Note: Prime checking for y , we will use Rabin Miller.

 ## Problem Source: 

 1) http://codeforces.com/gym/100753 


 ## Source: 
 1) http://codeforces.com/blog/entry/22317