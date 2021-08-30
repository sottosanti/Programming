(define PI 3.14159265358979323846)

(define (format x)
    (fluid-let ((flonum-unparser-cutoff '(absolute 2))) (number->string x))
)

; compute radius to the power of 2
(define (power-two x) (* x x))

; compute radius to the power of 3
(define (power-three x) (* x x x))




; -----SPHERE----AV 
(define (sphere-get-av shape av)
    (define radius (string->number (caddr shape)))
    
    (if(eqv? av 0)
        (* 4 PI (power-two radius))
        (* (/ 4 3) PI (power-three radius))
    )
)

; -----CONE----AV
(define (cone-get-av shape av)
    (define radius (string->number (caddr shape)))
    (define height (string->number (car (reverse shape))))

    (if(eqv? av 0)
        (* (* PI radius) (+ radius (sqrt (+ (power-two height) (power-two radius)))))
        (* 1/3 PI (power-two radius) height)
    )
)

; -----CUBOID----AV
(define (cuboid-get-av shape av)
    (define length (string->number (caddr shape)))
    (define width (string->number (cadr (reverse shape))))
    (define height (string->number (car (reverse shape))))

    (if(eqv? av 0)
        (+ (* 2 (* width length)) (+ (* 2 (* length height)) (* 2 (* height width)))) ; surface area
        (* length (* width height)) ; volume
    )
)

; -----CYLINDER----AV
(define (cylinder-get-av shape av)
    (define radius (string->number (caddr shape)))
    (define height (string->number (cadddr shape)))

    (if(eqv? av 0)
        (* 2.0 PI radius (+ radius height))
        (* PI (power-two radius) height)
    )
)

; helper for getting surface area and volume 
(define (get-area-av shape shape-type av)
    (if (eqv? av 0)
        (cond 
            ((equal? "sphere" shape-type) (sphere-get-av shape 0)) 
            ((equal? "cone" shape-type) (cone-get-av shape 0)) 
            ((equal? "cuboid" shape-type) (cuboid-get-av shape 0))
            ((equal? "cylinder" shape-type) (cylinder-get-av shape 0)) 
        )
        (cond 
            ((equal? "sphere" shape-type) (sphere-get-av shape 1)) 
            ((equal? "cone" shape-type) (cone-get-av shape 1)) 
            ((equal? "cuboid" shape-type) (cuboid-get-av shape 1))  
            ((equal? "cylinder" shape-type) (cylinder-get-av shape 1)) 
        )
    )
)





; -----SPHERE----INFO
(define (sphere-info shape)
    (define sphere-radius (string->number (caddr shape)))
    (display "Sphere: ") (display (car shape)) (display ", Radius=") (display sphere-radius) (newline)
    (display "\t") (display "Surface Area: ") (display (format (sphere-get-av shape 0))) (display ", Volume: ") (display (format (sphere-get-av shape 1))) (newline)
0)

; -----CONE----INFO
(define (cone-info shape)
    (define cone-radius (string->number (caddr shape)))
    (define cone-height (string->number (car (reverse shape))))
    (display "Cone: ") (display (car shape)) (display ", Radius=") (display cone-radius) (display ", Height=") (display cone-height) (newline)
    (display "\t") (display "Surface Area: ") (display (format (cone-get-av shape 0))) (display ", Volume: ") (display (format (cone-get-av shape 1))) (newline)
0)

; -----CUBOID----INFO
(define (cuboid-info shape)
    (define cuboid-length (string->number (caddr shape)))
    (define cuboid-width (string->number (cadr (reverse shape))))
    (define cuboid-height (string->number (car (reverse shape))))
    (display "Cuboid: ") (display (car shape)) (display ", Length=") (display cuboid-length) (display ", Width=") (display cuboid-width) (display ", Height=") (display cuboid-height) (newline)
    (display "\t") (display "Surface Area: ") (display (format (cuboid-get-av shape 0))) (display ", Volume: ") (display (format (cuboid-get-av shape 1))) (newline)
0)

; -----CYLINDER----INFO
(define (cylinder-info shape)
    (define cylinder-radius (string->number (caddr shape)))
    (define cylinder-height (string->number (cadddr shape)))
    (display "Cylinder: ") (display (car shape)) (display ", Radius=") (display cylinder-radius) (display ", Height=") (display cylinder-height) (newline)
    (display "\t") (display "Surface Area: ") (display (format (cylinder-get-av shape 0))) (display ", Volume: ") (display (format (cylinder-get-av shape 1))) (newline)
0)








; Start of building the list of lists
(define (str-split-helper line str list)
(cond
    ((string-null? line)
        (if (string-null? str)
    (reverse list)
    (reverse (cons str list))))
    ((char=? (string-ref line 0) #\space)
        (if (string-null? str)
            (str-split-helper (string-tail line 1) str list)
            (str-split-helper (string-tail line 1) "" (cons str list))))
    (else
        (str-split-helper (string-tail line 1)
                          (string-append str (string-head line 1))
                          list))))

(define (str-split line) 
    (str-split-helper line "" '())
)

; read every line of the file 
(define (get-list-helper port)
    (let loop ((lines '())
        (next-line (read-line port)))
        (if (eof-object? next-line) ; when we hit the end of file
            (reverse lines)         ; return the lines
            (loop (cons (str-split (string-trim-right next-line char-set:numeric)) lines) (read-line port)))) ; else loop, keeping this line
)

(define (create-shape-list filename)    
    (let   
        ((port (open-input-file filename)))
        (define list-of-shapes (get-list-helper port))
        (close-input-port port)
    list-of-shapes)
)


(define (Print list-of-shapes)
    (if (null? list-of-shapes)
        0 ; then return 0
        (begin ; else
            (cond 
                ((equal? "sphere" (cadr (car list-of-shapes))) 
                    (begin
                        (sphere-info (car list-of-shapes))
                        (Print (cdr list-of-shapes))
                    ))
                ((equal? "cone" (cadr (car list-of-shapes))) 
                    (begin
                        (cone-info (car list-of-shapes))
                        (Print (cdr list-of-shapes))
                    ))
                ((equal? "cuboid" (cadr (car list-of-shapes)))
                    (begin
                        (cuboid-info (car list-of-shapes))
                        (Print (cdr list-of-shapes))
                    ))
                ((equal? "cylinder" (cadr (car list-of-shapes))) 
                    (begin
                        (cylinder-info (car list-of-shapes))
                        (Print (cdr list-of-shapes))
                    ))
                (else 1) 
            )        
        )
    )
)


(define (compare op type value)
    (if (null? value)
        (if (null? type)
            (cond ; if they are coincidentally both empty meaning they are the same 
                ((equal? "==" op) #t)
                ((equal? ">=" op) #t)
                ((equal? "<=" op) #t)
                (else #f)
            )
            (cond ; if value is empty but there are still characters in type
                ((equal? "==" op) #f)
                ((equal? "<=" op) #f)
                ((equal? "<" op) #f)
                (else #t)
            )            
        )
        (begin ; still comparing 
            (if (char=? (car type) (car value)) 
                (compare op (cdr type) (cdr value))
                (cond
                    ((equal? "==" op) #f) ; failed the pre check 
                    ((equal? "!=" op) #t)
                    ((equal? ">=" op) 
                        (if (char>? (car type) (car value)) #t #f)
                    )
                    ((equal? "<=" op) 
                        (if (char<? (car type) (car value)) #t #f)
                    )
                    ((equal? ">" op) 
                        (if (char>? (car type) (car value)) #t #f)
                    )
                    (else 
                        (if (char<? (car type) (car value)) #t #f)
                    )
                )
            )
        )
    )
)


(define (Check-helper list-of-shapes name op value passed)
    (if (null? list-of-shapes)
        passed ; true so return the list
        (cond
            ((equal? "==" op)
                (cond 
                    ((equal? "type" name)
                        (if (string=? value (cadr (car list-of-shapes))) 
                            (Check-helper (cdr list-of-shapes) name op value (cons (car list-of-shapes) passed))
                            (Check-helper (cdr list-of-shapes) name op value passed)
                        )
                    )
                    ((equal? "area" name)
                        (if (eqv? value (get-area-av (car list-of-shapes) (cadr (car list-of-shapes)) 0)) 
                            (Check-helper (cdr list-of-shapes) name op value (cons (car list-of-shapes) passed))
                            (Check-helper (cdr list-of-shapes) name op value passed)
                        )
                    )
                    ((equal? "volume" name)
                        (if (eqv? value (get-area-av (car list-of-shapes) (cadr (car list-of-shapes)) 1)) 
                            (Check-helper (cdr list-of-shapes) name op value (cons (car list-of-shapes) passed))
                            (Check-helper (cdr list-of-shapes) name op value passed)
                        )
                    )
                )
            )
            ((equal? "!=" op)
                (cond 
                    ((equal? "type" name)
                        (if (compare op (string->list (cadr (car list-of-shapes))) (string->list value))
                            (cons (car list-of-shapes) (Check-helper (cdr list-of-shapes) name op value passed))
                            (Check-helper (cdr list-of-shapes) name op value passed)
                        )
                    )
                    ((equal? "area" name)
                        (if (eqv? (get-area-av (car list-of-shapes) (cadr (car list-of-shapes)) 0) value) 
                            (Check-helper (cdr list-of-shapes) name op value passed)
                            (cons (car list-of-shapes) (Check-helper (cdr list-of-shapes) name op value passed))
                        )
                    )
                   ((equal? "volume" name)
                        (if (eqv? (get-area-av (car list-of-shapes) (cadr (car list-of-shapes)) 1) value) 
                            (Check-helper (cdr list-of-shapes) name op value passed)
                            (Check-helper (cdr list-of-shapes) name op value (cons (car list-of-shapes) passed))
                        )
                    )
                )
            )
            ((equal? ">=" op) 
                (cond 
                    ((equal? "type" name)
                        (if (compare op (string->list (cadr (car list-of-shapes))) (string->list value)) 
                            (Check-helper (cdr list-of-shapes) name op value (cons (car list-of-shapes) passed))
                            (Check-helper (cdr list-of-shapes) name op value passed)
                        )
                    )
                    ((equal? "area" name)
                        (if (>= (get-area-av (car list-of-shapes) (cadr (car list-of-shapes)) 0) value) 
                            (Check-helper (cdr list-of-shapes) name op value (cons (car list-of-shapes) passed))
                            (Check-helper (cdr list-of-shapes) name op value passed)
                        )
                    )
                    ((equal? "volume" name)
                        (if (>= (get-area-av (car list-of-shapes) (cadr (car list-of-shapes)) 1) value) 
                            (Check-helper (cdr list-of-shapes) name op value (cons (car list-of-shapes) passed))
                            (Check-helper (cdr list-of-shapes) name op value passed)
                        )
                    )
                )
            )
            ((equal? "<=" op) 
                (cond 
                    ((equal? "type" name)
                        (if (compare op (string->list (cadr (car list-of-shapes))) (string->list value)) 
                            (Check-helper (cdr list-of-shapes) name op value (cons (car list-of-shapes) passed))
                            (Check-helper (cdr list-of-shapes) name op value passed)
                        )
                    )
                    ((equal? "area" name)
                        (if (<= (get-area-av (car list-of-shapes) (cadr (car list-of-shapes)) 0) value) 
                            (Check-helper (cdr list-of-shapes) name op value (cons (car list-of-shapes) passed))
                            (Check-helper (cdr list-of-shapes) name op value passed)
                        )
                    )
                    ((equal? "volume" name)
                        (if (<= (get-area-av (car list-of-shapes) (cadr (car list-of-shapes)) 1) value) 
                            (Check-helper (cdr list-of-shapes) name op value (cons (car list-of-shapes) passed))
                            (Check-helper (cdr list-of-shapes) name op value passed)
                        )
                    )
                )
            )
            ((equal? ">" op) 
                (cond 
                    ((equal? "type" name)
                        (if (compare op (string->list (cadr (car list-of-shapes))) (string->list value)) 
                            (Check-helper (cdr list-of-shapes) name op value (cons (car list-of-shapes) passed))
                            (Check-helper (cdr list-of-shapes) name op value passed)
                        )
                    )
                    ((equal? "area" name)
                        (if (> (get-area-av (car list-of-shapes) (cadr (car list-of-shapes)) 0) value) 
                            (Check-helper (cdr list-of-shapes) name op value (cons (car list-of-shapes) passed))
                            (Check-helper (cdr list-of-shapes) name op value passed)
                        )
                    )
                    ((equal? "volume" name)
                        (if (> (get-area-av (car list-of-shapes) (cadr (car list-of-shapes)) 1) value) 
                            (Check-helper (cdr list-of-shapes) name op value (cons (car list-of-shapes) passed))
                            (Check-helper (cdr list-of-shapes) name op value passed)
                        )
                    )
                )
            )
            (else 
                (cond 
                    ((equal? "type" name)
                        (if (compare op (string->list (cadr (car list-of-shapes))) (string->list value)) 
                            (Check-helper (cdr list-of-shapes) name op value (cons (car list-of-shapes) passed))
                            (Check-helper (cdr list-of-shapes) name op value passed)
                        )
                    )
                    ((equal? "area" name)
                        (if (< (get-area-av (car list-of-shapes) (cadr (car list-of-shapes)) 0) value) 
                            (Check-helper (cdr list-of-shapes) name op value (cons (car list-of-shapes) passed))
                            (Check-helper (cdr list-of-shapes) name op value passed)
                        )
                    )
                    ((equal? "volume" name)
                        (if (< (get-area-av (car list-of-shapes) (cadr (car list-of-shapes)) 1) value) 
                            (Check-helper (cdr list-of-shapes) name op value (cons (car list-of-shapes) passed))
                            (Check-helper (cdr list-of-shapes) name op value passed)
                        )
                    )
                )
            )
        )
    )   
)

(define (Check list-of-shapes args passed)
    (if (null? args)
        list-of-shapes ; if true return the list that passed all of the tests
        (Check  (Check-helper list-of-shapes (car args) (cadr args) (caddr args) '()) (cdddr args) '())
    )
)


(define (passedChecks command filename args)
    (define list-of-shapes (create-shape-list filename))
    (define shapes-that-passed (Check list-of-shapes args '()))
    (if (null? shapes-that-passed)
        (begin
            (display "There are no shapes that satisfy the condition(s)\n\n") 
        )
        (cond 
            ((equal? "print" command) 
                (begin (Print shapes-that-passed) (newline))
            )
            ((equal? "count" command) 
                (begin
                    (display "There are ") (display (length shapes-that-passed)) (display " shapes.\n\n")
                )
            )
            ((equal? "avg" command) 
                (begin
                    (display "avg(Surface Area)=")
                    (display (format (/ (fold-right + 0 (map (lambda (n) (get-area-av n (cadr n) 0)) shapes-that-passed)) (length shapes-that-passed)))) (newline)
                    (display "avg(Volume)=")
                    (display (format (/ (fold-right + 0 (map (lambda (n) (get-area-av n (cadr n) 1)) shapes-that-passed)) (length shapes-that-passed)))) (newline) (newline)
                )
            )
            ((equal? "total" command) 
                (begin
                    (display "total(Surface Area)=")
                    (display (format (fold-right + 0 (map (lambda (n) (get-area-av n (cadr n) 0)) shapes-that-passed)))) (newline)
                    (display "total(Volume)=")
                    (display (format (fold-right + 0 (map (lambda (n) (get-area-av n (cadr n) 1)) shapes-that-passed)))) (newline) (newline)
                )
            )
            ((equal? "min" command) 
                (begin
                    (display "min(Surface Area)=")
                    (display (format (car (sort (map (lambda (n) (get-area-av n (cadr n) 0)) shapes-that-passed) <)))) (newline)
                    (display "min(Volume)=")
                    (display (format (car (sort (map (lambda (n) (get-area-av n (cadr n) 1)) shapes-that-passed) <)))) (newline) (newline)
                )
            )
            ((equal? "max" command) 
                (begin                    
                    (display "max(Surface Area)=")
                    (display (format (car (sort (map (lambda (n) (get-area-av n (cadr n) 0)) shapes-that-passed) >)))) (newline)
                    (display "max(Volume)=")
                    (display (format (car (sort (map (lambda (n) (get-area-av n (cadr n) 1)) shapes-that-passed) >)))) (newline) (newline)
                )
            )
            (else 1) ; else return
        )
    )
)


(define (checkTwo command filename args)
    (cond
        ((eq? (modulo (length args) 3) 0) (passedChecks command filename args)) 
        (else (begin ; else
            (display "Incorrect number of arguments.\n\n")
        1)) ; else return    
    )
)

(define (perform command filename . args)
    (cond
        ((file-exists? filename) (checkTwo command filename args))
        (else (begin ; else
            (display "Unable to open ") (display filename) (display " for reading.\n\n")
        1))
    )
)
