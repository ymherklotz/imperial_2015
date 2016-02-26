testbench-opt1.s

Testbench for opt1 code with test data. 
To test your code:
(1) Paste your solution (subroutine SMUL64X64) into VisUAL after the testbench code. 
(2) Run the code.
(3) On successful termination of all tests R0 = 123

Otherwise:
R0 = -1 (data out error in one of the tests, R5 contains test number)
R0 = -2 (your code works OK but changes R4-R12 which is not allowed)

If your code fully passes this testbench it will fully pass my "correctness" mark. In this case you pass the pseudo-code mark as well and obtain at least 50% for the project mark.

If your code partially passes this testbench (e.g. it stops at negative numbers) you will still get some part of the code mark. In this case your pseudo-code description will be separately marked.



test64x64.py (NOT NEEDED FOR NORMAL TESTING)
Python script (runs under Python 2.7) in case you want to generate NEW test data for the testbench. Will not normally be needed.

