template <typename Return, typename... Args>
struct FunctionTraits_ {
  FunctionTraits_(std::function<Return(Args...)> f) {}
  using return_type = Return;
  using arg_types = std::tuple<Args...>;

  enum { arity = sizeof...(Args) };
  template <size_t i>
  struct arg_type {
    using type = typename std::tuple_element<i, arg_types>::type;
  };
};

template <typename Function>
struct FunctionTraits : public decltype(FunctionTraits_(
                            std::function{std::declval<Function>()})) {};

