#include "concepts.h"

#include <list>
#include <vector>
#include <forward_list>

int main(int, char**) {
    std::forward_list fl { 1, 2, 3, 4, 5 };
    ForwardIterator fi { fl.begin() };

    std::list bl { 1, 2, 3, 4, 5 };
    BidirectionalIterator bi { bl.begin() };

    std::vector ra { 1, 2, 3, 4, 5 };
    RandomAccessIterator ri { ra.begin() };

    ForwardIterator af { bl.begin() };

#if false // neither of these will compile!!

    BidirectionalIterator nb { fl.begin() };
    RandomAccessIterator  nr { bl.begin() };

#endif

    return 0;
}
