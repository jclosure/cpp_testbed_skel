# Lukas Bernreiter
Date: 11/7/2024
API Design 


# API Definition
Headers define public interface
Library
Documentation

### Interface design

Doesn't raise additional questions (don't confuse your users)
Easy to read and understand (BY EVERYONE)!
Clearly express what is input and what is output
Intuitive naming (be very clear and concise)

### What makes a good design
- Doesn't rely on comments for how to correctly use api
- How are errors handled
- Avoids hard coded assumptions
- Reduce coupling to other internal and external deps
- White/black/gray box testing
- Random inputs catch bugs
- Documentation
    - What are the capabilities
    - What are the boundaries
    - Recommendations for best practice usage


Enforce the caller uses the return val
```
[[nodiscard]]

```