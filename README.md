# anagram_derivation

An anagram derivation is a N-letter word derived from a N-1 letter word by adding a letter and rearranging. For example, here is a derivation of `aliens`

`ail + s = sail + n = nails + e = aliens`

Write a program that will find the longest such derivation from a specific 3-letter word (one word provided by user) in a list of words where every derived word also exists in the list of words.

`words = {ail, tennis, nails, desk, aliens, table, engine, sail, etc....}`

Requirements:
- fully working application
- documentation of used algorithm (can be in a form of comments in code)
- application should be able to operate on external dictionary - text file where each line is another word


Assumptions I have made:
----

- External dictionary should exist. Otherwise exception will be thrown
- Words in external dictionary should be ASCII chars. I don't want handle ążźć etc chars.


----
Algorithm description
----

Assumptions:
---
If words have the same subset of letters like:
`bananna` and `nabanna`
We can ignore one of them they have the same length and for our solution isn't important. From those 2 words we can create the same derivations. Remember we are looking for longest one!

For each word in dictionary create a key in map.
Key will be created in this way:
- take `word` from dictionary
- normalize it (all big letters to small ones) and other "normalizing" stuff you want
- sort `word` letters
- insert to our hash map where key will be sorted letters from `word`
eg. `snail` will be: `ailns`
So in map we will add `map['ailns'] = 'snail'`

So as you can see we could have key's collision but as i write before it doesn't matter!
