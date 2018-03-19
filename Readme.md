## Graph Theory
* A* Search / IDA* Search
	1. Article:
		* http://rendon.x10.mx/a-star/
	2. Video:
		* https://www.youtube.com/watch?v=DhtSZhakyOo
		* https://www.youtube.com/watch?v=l9tWYsUnzkw (Heuristic value )
		* https://www.youtube.com/watch?v=b19e0_NlD-U (8 Puzzle Problem ) 
		* http://en.wikipedia.org/wiki/IDA* (Difference between A* & IDA*)

* Bellman Ford 
	1. Article:
		* http://www.bogotobogo.com/Algorithms/Bellman_Ford_shortestpath_algorithm.php

	2. Video:
		* https://www.youtube.com/watch?v=05WQNgR4Urk

* Euler Circuit/Path Print
	1. Article:
		* http://www.graph-magics.com/articles/euler.php
		
* Max Flow - Min Cut
	1. Article:
		* http://www.shafaetsplanet.com/planetcoding/?p=2195

* Strongly Connected Component: (Kosaraju + Tarjan )
	1. Video:
		* https://www.youtube.com/watch?v=PZQ0Pdk15RA  
		* http://en.algoritmy.net/article/44220/Tarjans-algorithm

## Bit Wise Operation 
1. Article :
   	* http://zobayer.blogspot.com/2009/12/bitwise-operations-in-cc-part-1.html
   	* http://zobayer.blogspot.com/2009/12/bitwise-operations-in-c-part-2.html
   	* http://zobayer.blogspot.com/2009/12/bitwise-operations-in-c-part-3.html

## Convex Hull
1. Article:
   	* http://rendon.x10.mx/andrews-convex-hull-algorithm/

## Expected Value / Probability
1. Article:
	* http://www.codechef.com/wiki/tutorial-expectation 

## Gaussian Elimination
1. Video:
  	* https://www.youtube.com/watch?v=2j5Ic2V7wq4

## Histogram 
1. Article:
	* http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

## Kadane’s Algorithm (Find Max Sub-Array)
1. Article:
	* http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
2. Video:
	* https://www.youtube.com/watch?v=ohHWQf1HDfU
> Another way to find Max Sub-array by use 2 pointer : Suppose i & j 2 point . i+1 = left point of a sub array , j=right point of sub-array . We iterate j from left to right over our array and update our answer variable by max(answer, q_sum[j]-q_sum[i] ) . We update i if (array[i] > array[j] ) coz we all time try to cut out less value from our answer . R8 ?

## String Matching
* Knuth morris pratt:
	1. Article:
	    *  http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm
	2. Video :
		* https://www.youtube.com/watch?v=v82y5TCcBhQ
	> Note : In failure function of KMP , we build an array lps. lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i].


* Z algo
	1. Article:
		* http://codeforces.com/blog/entry/3107

* Suffix Array
	1. Article:
		* https://discuss.codechef.com/questions/21385/a-tutorial-on-suffix-arrays

* String Hashing :
	1. Article:
		* http://threads-iiith.quora.com/String-Hashing-for-competitive-programming 
	> Double hashing with unordered_map require hash function to overload. Here is the [function](https://github.com/Kimbbakar/Contest-Resource/blob/master/String/Template/Unorderd%20map%20with%20pair%20.cpp).

## Matrix Exponential
1. Article:
	* http://zobayer.blogspot.com/2010/11/matrix-exponentiation.html

## Meet in the middle
1. Article:
	* http://www.shafaetsplanet.com/planetcoding/?p=1756

2. Problem Link:
	* http://codeforces.com/problemset/problem/912/E

## Game Theory 
* Nim Game:
	1. Video Tutorial:
		* https://www.youtube.com/watch?v=ORaGSyewF9Q
	2. Article:
		* http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=algorithmGames

* Staircase Case Nim:
	1. Article:
		* http://codeforces.com/blog/entry/44651
* Problem:
	* https://www.hackerrank.com/contests/5-days-of-game-theory/challenges

## Dat Structure
* Segment Tree 
	1. Article:
		* (Segement Tree) http://www.shafaetsplanet.com/planetcoding/?p=1557
		* (Lazy Propagation) http://www.shafaetsplanet.com/planetcoding/?p=1591

 
* Two Pointer 
	1. Post:
		* http://codeforces.com/blog/entry/4586#comment-93047


* MO’s Algorithm
	1. Article:
		* https://blog.anudeep2011.com/mos-algorithm/
		* [MO's on Tree]( http://codeforces.com/blog/entry/43230)
	2. Video:
		* [MO's with Update] (https://www.youtube.com/watch?v=gUpfwVRXhNY)

* Trie / Prefix Tree / Radix Tree
	1. Article:
		* http://www.shafaetsplanet.com/planetcoding/?p=1679


## Number Theory 
* Calculate (a^b)^c % mod 
	1. Article:
		* http://stackoverflow.com/questions/4223313/finding-abc-mod-m




