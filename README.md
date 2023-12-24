# FunctionTraits

## Descriptions

Simple FunctionTraits header-only "tool", inspired by [stackoverflow discussion](https://stackoverflow.com/questions/7943525/is-it-possible-to-figure-out-the-parameter-type-and-return-type-of-a-lambda)

Work with both regular functions and functors.
Doesn't support generic lambdas `[](auto x) { return x; }`cpp

## Usage

```cpp
std::size_t func(int, const std::string &s) { return s.size(); }
auto lambda = [](int, const std::string &s) { return s.size(); };

int main() {
  using traits = FunctionTraits<decltype(func)>;
  // using traits = FunctionTraits<decltype(lambda)>;

  static_assert(traits::arity == 2);
  static_assert(std::is_same_v<traits::return_type, std::size_t>);
  static_assert(std::is_same_v<traits::arg_type<0>::type, int>);
  static_assert(std::is_same_v<traits::arg_type<1>::type, const std::string &>);
  static_assert(std::is_same_v<traits::arg_types, std::tuple<int, const std::string &>>);

  return 0;
}
```
