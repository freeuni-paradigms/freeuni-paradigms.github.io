; exercise.scm
; 1)
(define (digits n)
 (if (zero? n)
     '()
     (cons (remainder n 10) (digits (quotient n 10))))
)

(define (length lst)
    (if (null? lst)
        0
        (+ 1 (length (cdr lst))))
)

(define (narcissistic? n)
    ( equal? (apply + (
        map (lambda (x) ( expt x (length (digits n)))) (digits n)
    )) n)
)

; 2)

(define (isEqual a b)
    (if (equal? a b)
        1
        0)
)

(define (freq n lst)
    (apply + (map (lambda (x) (isEqual x n)) lst))
)

(define (calculateFreq lst)
    (map (lambda (n) (freq n lst)) '(0 1 2 3 4 5 6 7 8 9)))




(define (reverse lst)
    (if (null? (cdr lst))
        lst
        (append (reverse (cdr lst)) (list (car lst))))
)