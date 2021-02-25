
# Regular expressions in Python

# Glob != regular expression


Type strings to match items exactly
password, 111, Aaaa

Special Characters:
	. ^ $ * ? { } [ ] | \\ ( )

. -- full stop matches any single character except newline character ("\n"), same as ? in linux/glob
? -- 1 or zero characters should appear r".?" r"spaghett?i"
* -- wildcard/ Kleene star. 0 or any number of the character r"hel*o*" -- hellooooooo
+ -- plus sign, char should appear 1 or more times r"hel+o" -- helo
[ ] -- Any of these characters my match. r"[hHJj]ello"
	[a-zA-Z0-9] ... [l-p] == [lmnop]
    r"[sZSz]+orry"

\w -- Matches and "word" [a-zA-Z0-9_]
\W -- Matches anything that is no a word character r"\W\w\w\w\W" (may end a sentence)

\s -- Matches any white space character [\t\n \r\f\v]
\S -- Matches any non-white space character  r"\S\w\w\w\S" (in the middle of a sentence) 

\d -- Matches any numeric value

^ -- When used in a character class, it negates it. \S --? [^\t\n \r\f\v]
^ -- Otherwise, means the start of a string r"^\w\w\w[ ]"

$ -- Matches the end of a string, r"\w\w\w!$"

{x} -- Match the previous characer x time. r"\w{3}"
{x,y} -- Match the previous character from x to y times (inclusive?). r"hel{2,3}o"
{x,} -- Match the previous character at least x times.
{,y} -- Match the previous character at most y times.

() -- Groups a list of regex expressions.
