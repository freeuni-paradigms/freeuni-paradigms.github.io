(define (farthest-node node)
  (if (null? (cadr node))
      (car node)
      (+ (car node) (apply min (map farthest-node (cadr node))))))
