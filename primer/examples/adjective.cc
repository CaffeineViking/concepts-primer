#include "concepts.h"

#include <forward_list>
#include <list>


template<Sortable Range>
void sort(Range& range);

void sort(Sortable auto& range);

template<RandomAccessIterator Iterator>
void sort(Iterator begin, Iterator end);

template<typename In1, typename In2, typename Out>
    requires Mergeable<In1, In2, Out>
Out merge(In1 f1, In1 l1, In2 f2, In2 l2, Out out);

int main(int, char**) {

#if true // Replace with 'false'!
    std::list l { 1, 2, 3, 4, 5 };
#else
    // Won't compile! ForwardIterator does
    // not satisfy BidirectionalIterator!
    std::forward_list l { 1, 2, 3, 4, 5 };
#endif

    BidirectionalIterator auto iterator = l.begin();

    iterator == l.begin(); // Stops warnings!
    return 0;
}
