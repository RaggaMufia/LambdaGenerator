e --> x,e.
e --> [].
x --> [0].
x --> [1].
x --> ['x'].
x --> ['y'].
x --> ['l'].
x --> ['['].
x --> [']'].
x --> ['('].
x --> [')'].
x --> ['.'].
x --> ['<'].
x --> ['|'].

run :- tell('result.txt'),
(
	between(1,6,Y),length(X,Y),e(X,[]),
	element(X),nl,
	fail;
	told
).

element([]).
element([A|B]) :- write(A),element(B). 