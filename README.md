# IOA https://mtt.etf.bg.ac.rs/si/ioa.htm

## `nTuples(int n, int k)`

### Description
This function calculates variations with repetition, specifically n^k.

### Parameters
- `n` (int): The number of items to choose from.
- `k` (int): The number of items to choose in each variation.

### Usage
```cpp
#include "ioaalgorithms.h"

int main() {
    int n = 5;
    int k = 3;
    int result = nTuples(n, k);
    std::cout << "Variations with repetition: " << result << std::endl;
    return 0;
}

