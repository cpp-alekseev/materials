
template <typename First, typename Second, typename... Types>
struct is_homogeneous {
	static constexpr bool value = std::is_same_v<First, Second>
        	&& is_homogeneous<Second, Types...>::value;
};

template <typename First, typename Second>
struct is_homogeneous<First, Second> {
	static constexpr bool value = std::is_same_v<First, Second>;
};

template <typename C, typename... Ts> 
using is_homogeneous2 = std::bool_constant<(... && std::is_same<C,Ts>::value)>;
