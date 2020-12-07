(define (from-to from to)
  (if (>= from to) (cons from (from-to (- from 1) to))
      '()))
