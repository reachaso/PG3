#pragma once
#include <type_traits> // std::common_type_t

template <typename T1, typename T2>
class cf_Min {
public:
    using ReturnT = std::common_type_t<T1, T2>;

    cf_Min(T1 a, T2 b) : a_(a), b_(b) {}

    // 2つのメンバを比べて小さい方を返す
    ReturnT Min() const {
        ReturnT aa = static_cast<ReturnT>(a_);
        ReturnT bb = static_cast<ReturnT>(b_);
        return (aa < bb) ? aa : bb;
    }

private:
    T1 a_;
    T2 b_;
};
