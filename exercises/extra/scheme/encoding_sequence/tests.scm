(load "encode-sequence.scm")

; TEST ALL:
(display (equal? (encode-sequence '(a a a a b c c a a d e e e e)) '((4  a) (1 b) (2 c) (2 a) (1 d) (4 e))))(newline)

(display (equal? (encode-sequence '(1 2 2 3 3 3 4 4 4 4 5 5 5 5 5)) '((1 1) (2 2) (3 3) (4 4) (5 5))))(newline)

(display (equal? (encode-sequence '()) '()))(newline)

(display (equal? (encode-sequence '(abc abc abc abc)) '((4  abc))))(newline)

(display (equal? (encode-sequence '((1) (1) (1) (a) (a))) '((3 (1)) (2 (a)))))(newline)
