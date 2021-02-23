
# Regular expressions in Python

# Glob != regular expression


Type strings to match items exactly
password, 111, Aaaa

Special Characters:
	. ^ $ * ? { } [ ] | \\ ( )

. -- full stop matches any single character except newline character ("\n"), same as ? in linux/glob
? -- 1 or zero characters should appear r".?"
* -- wildcard/ Kleene star. 0 or any number of the character "hello\*" -- hellooooooo
[ ] -- Any of these characters my match. r"[hHJj]ello"
	[a-zA-Z0-9] ... [l-p] == [lmnop]

