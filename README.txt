** User keyboard/< input functionallity added that was in p0 but missing from p1(-5%).

** Nearly a week was spent looking for bugs that didnt exist. Several examples were going into infinite loops or failing to take the next token and i simply could not find the code causing it. Turns out that when i copied the test file text from canvas and pasted it into vim via ssh some mysterious blank characters were added which messed it all up. Removing these special blanks fixed the problem.
