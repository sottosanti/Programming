list(Op, Ref, List) :- (
    Op=('=='), findall([X, Y, Z], (pay(X, Y, Z), Z=:=Ref), List);
    Op=('!='), findall([X, Y, Z], (pay(X, Y, Z), Z=\=Ref), List);
    Op=('>'), findall([X, Y, Z], (pay(X, Y, Z), Z>Ref), List);
    Op=('>='), findall([X, Y, Z], (pay(X, Y, Z), Z>=Ref), List);
    Op=('<'), findall([X, Y, Z], (pay(X, Y, Z), Z<Ref), List);
    Op=('<='), findall([X, Y, Z], (pay(X, Y, Z), Z=<Ref), List)
).

count(Op, Ref, Count) :- (
    Op=('=='), findall(Pay, (pay(First, Last, Pay), Pay=:=Ref), List), length(List, Count);
    Op=('!='), findall(Pay, (pay(First, Last, Pay), Pay=\=Ref), List), length(List, Count);
    Op=('>'), findall(Pay, (pay(First, Last, Pay), Pay>Ref), List), length(List, Count);
    Op=('>='), findall(Pay, (pay(First, Last, Pay), Pay>=Ref), List), length(List, Count);
    Op=('<'), findall(Pay, (pay(First, Last, Pay), Pay<Ref), List), length(List, Count);
    Op=('<='), findall(Pay, (pay(First, Last, Pay), Pay=<Ref), List), length(List, Count)
).

sum([], 0).
sum([H|T], Sum) :- 
    sum(T, Rest),
    Sum is H + Rest.  

total(Op, Ref, Total) :- (
    Op=('=='), findall(Pay, (pay(First, Last, Pay), Pay=:=Ref), List), sum(List, Total);
    Op=('!='), findall(Pay, (pay(First, Last, Pay), Pay=\=Ref), List), sum(List, Total);
    Op=('>'), findall(Pay, (pay(First, Last, Pay), Pay>Ref), List), sum(List, Total);
    Op=('>='), findall(Pay, (pay(First, Last, Pay), Pay>=Ref), List), sum(List, Total);
    Op=('<'), findall(Pay, (pay(First, Last, Pay), Pay<Ref), List), sum(List, Total);
    Op=('<='), findall(Pay, (pay(First, Last, Pay), Pay=<Ref), List), sum(List, Total)
).

average( List, Average ):- 
    sum( List, Sum ),
    length( List, Length ),
    Length > 0, 
    Average is Sum / Length.

avg(Op, Ref, Avg) :- (
    Op=('=='), findall(Pay, (pay(First, Last, Pay), Pay=:=Ref), List), average(List, Avg);
    Op=('!='), findall(Pay, (pay(First, Last, Pay), Pay=\=Ref), List), average(List, Avg);
    Op=('>'), findall(Pay, (pay(First, Last, Pay), Pay>Ref), List), average(List, Avg);
    Op=('>='), findall(Pay, (pay(First, Last, Pay), Pay>=Ref), List), average(List, Avg);
    Op=('<'), findall(Pay, (pay(First, Last, Pay), Pay<Ref), List), average(List, Avg);
    Op=('<='), findall(Pay, (pay(First, Last, Pay), Pay=<Ref), List), average(List, Avg)
).


findx([], R, R).
findx([X|Xs], WK, R) :-
    X > WK,
    findx(Xs, X, R).

findx([X|Xs], WK, R) :-
    X =< WK,
    findx(Xs, WK, R).

findx([X|Xs], R) :- findx(Xs, X, R). 


max(Op, Ref, Max) :- (
    Op=('=='), findall(Pay, (pay(First, Last, Pay), Pay=:=Ref), List), findx(List, Max);
    Op=('!='), findall(Pay, (pay(First, Last, Pay), Pay=\=Ref), List), findx(List, Max);
    Op=('>'), findall(Pay, (pay(First, Last, Pay), Pay>Ref), List), findx(List, Max);
    Op=('>='), findall(Pay, (pay(First, Last, Pay), Pay>=Ref), List), findx(List, Max);
    Op=('<'), findall(Pay, (pay(First, Last, Pay), Pay<Ref), List), findx(List, Max);
    Op=('<='), findall(Pay, (pay(First, Last, Pay), Pay=<Ref), List), findx(List, Max)
).

findmin([], R, R).
findmin([X|Xs], WK, R) :-
    X < WK,
    findmin(Xs, X, R).

findmin([X|Xs], WK, R) :-
    X >= WK,
    findmin(Xs, WK, R).

findmin([X|Xs], R) :- findmin(Xs, X, R). 


min(Op, Ref, Min) :- (
    Op=('=='), findall(Pay, (pay(First, Last, Pay), Pay=:=Ref), List), findmin(List, Min);
    Op=('!='), findall(Pay, (pay(First, Last, Pay), Pay=\=Ref), List), findmin(List, Min);
    Op=('>'), findall(Pay, (pay(First, Last, Pay), Pay>Ref), List), findmin(List, Min);
    Op=('>='), findall(Pay, (pay(First, Last, Pay), Pay>=Ref), List), findmin(List, Min);
    Op=('<'), findall(Pay, (pay(First, Last, Pay), Pay<Ref), List), findmin(List, Min);
    Op=('<='), findall(Pay, (pay(First, Last, Pay), Pay=<Ref), List), findmin(List, Min)
).