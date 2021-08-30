pay(First, Last, Pay) :- salaried(First, Last, Wsalary),
    Pay is Wsalary.

pay(First, Last, Pay) :- hourly(First, Last, Hours, Rate),
    Hours < 40,
    Pay is Hours*Rate.

pay(First, Last, Pay) :- hourly(First, Last, Hours, Rate),
    between(40, 50, Hours),
    Pay is 40*Rate + ((Hours-40)*(Rate*1.5)).  

pay(First, Last, Pay) :- hourly(First, Last, Hours, Rate),
    Hours > 50,
    Pay is 40*Rate + ((10)*(Rate*1.5)) + ((Hours-50)*(Rate*2)).

pay(First, Last, Pay) :- commission(First, Last, Min_Salary, Amount, Rate),
    Amount*Rate > Min_Salary,
    Pay is Amount*Rate.

pay(First, Last, Pay) :- commission(First, Last, Min_Salary, Amount, Rate),
    Amount*Rate =< Min_Salary,
    Pay is Min_Salary.