Object subclass: #Main.
Main instanceVariableNames: 'temp'.

Main extend [
  init: name [
    temp :=name.
    ^self.
  ]
  getName [
    ^temp.
  ]

]



Main class extend[
  new: name [
    | obj |
    obj := super new.
    obj init: name.
    ^obj.
  ]
]


| var |

var := Main new: 'Stephen'.
var getName displayNl.
