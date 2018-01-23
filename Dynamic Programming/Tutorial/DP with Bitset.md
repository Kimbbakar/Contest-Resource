## Sample Problem:

We have N different numbers, we need to answer how many different number sum we can get from the all the subset of N numbers.

## Idea: 

At first , consider A[] is the array of all N number a
And MAX = Summation (A[i]) (1<=i<=N)



Here is the sudo code of O(MAX*n) complexity.

```
dp[MAX];
dp[0]=1 // coz it is all time possible to make 0

for(int i = 0; i < N; i++)
    for(int j = MAX; j>=A[i]; j--)
        dp[j]=dp[j-A[i] ] // if j-A[i] is possible to build , thn j is also possible 

cout<<dp.count(1);

```

Now by using bit set , we can boil down the whole solution into O(n). Is not it cool !
```
bitset<MAX> dp ;  

dp.set(0);

for(int i = 0; i < n; i++)
	dp |= dp  << a[i]; 
cout << dp.count() << '\n'; 
```

For example we have a 11 size bitset. And value of it "00100100101".
It means:

0 is possible to build. <br>
1 not is possible ..... <br>
2 is .................. <br>
3 is not .............. <br>
4 is not .............. <br>
5 is .................. <br> 
6 is not .............. <br>
7 is not .............. <br>
8 is .................. <br>
9 is not .............. <br>
10 is not ............. <br>

now a value a[i]=2 . After (dp<<a[i]) , new string will be "10010010100".

It means we add 2 with all existing sum.

So if we do "dp |= dp  << a[i]" , we will get all old set + all new set after adding 2.



## Problem Resource:

1) http://lightoj.com/volume_showproblem.php?problem=1147
2) https://www.codechef.com/SNCKEL16/problems/RWALK/
