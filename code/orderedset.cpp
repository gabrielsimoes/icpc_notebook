#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename tA, typename tB=null_type> using ord_set = tree<tA, tB, less<tA>, rb_tree_tag, tree_order_statistics_node_update>;
// map: tA -> tB with the less<tA> comparison function
// can be used as a normal map
// s.find_by_order(k) :: returns iterator to the k-th element (0-indexed) (or s.end())
// s.order_of_key(x)  :: returns how many elements are strictly less than x
