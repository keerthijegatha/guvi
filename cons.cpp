#include <string>
#include <cstddef>
using namespace std::literals;
 template<typename T>
concept Hashable = requires(T a) {
    { std::hash<T>{}(a) } -> std::size_t;
};
 struct meow {};
 template<Hashable T>
void f(T); 
int main() {
  f("abc"s); // OK, std::string satisfies Hashable
  f(meow{}); // Error: meow does not satisfy Hashable
}
