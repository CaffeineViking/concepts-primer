#include "concepts.h"

#include <forward_list>
#include <list>

template<typename Range>
    requires Sortable<Range>
void sort(Range& range);


template<typename Iterator>
    requires RandomAccessIterator<Iterator>
void sort(Iterator begin, Iterator end);

template<typename In1, typename In2, typename Out>
    requires Mergeable<In1, In2, Out>
Out merge(In1 f1, In1 l1, In2 f2, In2 l2, Out out);

template<auto N>
    requires Even<N>
auto square_even() {
    return N*N;
}

int main(int, char**) {

#if true // Replace with 'false'!
    std::list l { 1, 2, 3, 4, 5 };
#else
    // Won't compile! ForwardIterator does
    // not satisfy BidirectionalIterator!
    std::forward_list l { 1, 2, 3, 4, 5 };
#endif

#if false

// No way to do this within Concepts Zero!

#endif

    return 0;
}
