# Road Network Optimization Program

## Problem Description

You are tasked with redesigning the road system of an imaginary country composed of **N** cities (numbered from 0 to N-1). The current road network is in disarray; some cities are not connected at all, while others are connected by multiple paths, leading to inefficient traffic routing. The goal is to reconstruct the road network so that every pair of distinct cities is connected by exactly one path, ensuring the most efficient traffic flow possible.

### Objective

Minimize the total cost of reconstructing the road network by:
1. **Buidling new roads** where needed.
2. **Destroying existing roads** to eliminate redundant paths.

### Input Description

The program takes a single line of input ocnsisting of three strings separated by spaces. Theses strings represent:

1. **`Country`**: A flattened two-dimensional array representing the existing roads between cities.
- `country[i][j] = 1` indicates a road exists between city `i` and city `j`.
- `country[i][j] = 0` indicates no road exists between city `i` and city `j`.

2. **`build`**: A flattened two-dimensional array representing the cost of building roads between cities.
- Costs are represented using English letters:
    - `A-Z` represent costs from 0 to 25.
    - `a-z` represent costs from 26 to 51.

3. **`destroy`**: A flattened two-dimensional array representing the cost of destroying roads between cities.
- Costs are represented using English letters in the same way as `build`.

### Sample Scenarios

1.  **Input**: `011,101,110 ABD,BAC,DCA ABD,BAC,DCA`
    **Output**: 1
    **Explanation**: Three cities form a connected triangle; destroy one road to reduce the multiple paths. The minimal cost is `1`.

2.  **Input**: `011000,101000,110000,000011,000101,000110 ABDFFF,BACFFF,DCAFFF,FFFABD,FFFBAC,FFFDCA ABDFFF,BACFFF,DCAFFF,FFFABD,FFFBAC,FFFDCA`
    **Output**: `7`
    **Explanation**: We have six cities forming two separate triangles. Destroy one road in each triangle (costs 1 for each road) and then join the triangles by a new road (costs 5). The minimal cost is `7`.

3.  **Input**: `0001,0001,0001,1110 AfOj,fAcC,OcAP,jCPA AWFH,WAxU,FxAV,HUVA`
    **Output**: `0`
    **Explanation**: Four cities are connected in such a way that there is exactly one path between each pair of cities. No reconstruction is needed, so the minimal cost is `0`.