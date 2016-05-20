/*************************************************************************
 * vec2 struct
 *
 * struct for vectors that contain an x and y component
 *
 *************************************************************************/
#ifndef APPM_VEC2_H_
#define APPM_VEC2_H_

struct vec2
{
/*************************************************************************
 * Data Members
 *************************************************************************/
    union { float x; float r; float s; };
    union { float y; float g; float t; };
    //float x, y;
/*************************************************************************
 * Constructors
 *************************************************************************/
    vec2()
    {
        this->x = 0.0f;
        this->y = 0.0f;
    }
    
    vec2(const vec2& vec)
    {
        this->x = vec.x;
        this->y = vec.y;
    }
    
    vec2(const float x, const float y)
    {
        this->x = x;
        this->y = y;
    }
/*************************************************************************
 * Base Arithmetic Functions
 *************************************************************************/
// Addition
    vec2& add(const vec2& rhs)
    {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }
    
    vec2& add(const float i)
    {
        this->x += i;
        this->y += i;
        return *this;
    }
    
    vec2& add(const float x, const float y)
    {
        this->x += x;
        this->y += y;
        return *this;
    }
    
// Subtraction
    vec2& subtract(const vec2& rhs)
    {
        this->x -= rhs.x;
        this->y -= rhs.y;
        return *this;
        
    }
    
    vec2& subtract(const float i)
    {
        this->x -= i;
        this->y -= i;
        return *this;
    }
    
    vec2& subtract(const float x, const float y)
    {
        this->x -= x;
        this->y -= y;
        return *this;
    }
    
// Multiplication
    vec2& multiply(const vec2& rhs)
    {
        this->x *= rhs.x;
        this->y *= rhs.y;
        return *this;
    }
    
    vec2& multiply(const float i)                      
    {
        this->x *= i;
        this->y *= i;
        return *this;
    }
    
    vec2& multiply(const float x, const float y)
    {
        this->x *= x;
        this->y *= y;
        return *this;
    }
    
// Division
    vec2& divide(const vec2& rhs)
    {
        this->x /= rhs.x;
        this->y /= rhs.y;
        return *this;
    }
    
    vec2& divide(const float i)
    {
        this->x /= i;
        this->y /= i;
        return *this;
    }
    
    vec2& divide(const float x, const float y)
    {
        this->x /= x;
        this->y /= y;
        return *this;
    }
/*************************************************************************
 * Operator Overloading
 *************************************************************************/
// Addition
    vec2 operator+(const vec2& vec)
    {
        vec2 tmpVec(*this);
        tmpVec.x = this->x + vec.x;
        tmpVec.y = this->y + vec.y;
        return tmpVec;
    }
    vec2 operator+(const float& i)
    {
        vec2 tmpVec(*this);
        tmpVec.x = this->x + i;
        tmpVec.y = this->y + i;
        return tmpVec;
    }
    friend vec2 operator+(float i, vec2& vec)
    {
        vec2 tmpVec(vec);
        tmpVec.x = i + vec.x;
        tmpVec.y = i + vec.y;
        return tmpVec;
    }
    vec2& operator+=(const vec2& vec)
    {
        return this->add(vec);
    }
    vec2& operator+=(const float i)
    {
        return this->add(i);
    }
    vec2& operator++()
    {
        this->x++;
        this->y++;
        return *this;
    }
    vec2 operator++(int i)
    {
        vec2 tmpVec(*this);
        this->x++;
        this->y++;
        return tmpVec;
    }
// Subtraction
    vec2 operator-(const vec2& vec)
    {
        vec2 tmpVec(vec);
        tmpVec.x = this->x - vec.x;
        tmpVec.y = this->y - vec.y;
        return tmpVec;
    }
    vec2 operator-(const float i)
    {
        vec2 tmpVec(*this);
        tmpVec.x = this->x - i;
        tmpVec.y = this->y - i;
        return tmpVec;
    }
    friend vec2 operator-(float i, vec2& vec)
    {
        vec2 tmpVec(vec);
        tmpVec.x = i - vec.x;
        tmpVec.y = i - vec.y;
        return tmpVec;
    }
    vec2& operator-=(const vec2& vec)
    {
        return this->subtract(vec);
    }
    vec2& operator-=(const float i)
    {
        return this->subtract(i);
    }
    vec2& operator--()
    {
        this->x--;
        this->y--;
        return *this;
    }
    vec2 operator--(int)
    {
        vec2 tmpVec(*this);
        this->x--;
        this->y--;
        return tmpVec;
    }
// Multiplication
    vec2 operator*(const vec2& vec)
    {
        vec2 tmpVec(*this);
        tmpVec.x = this->x * vec.x;
        tmpVec.y = this->y * vec.y;
        return tmpVec;
    }
    vec2 operator*(const float i)
    {
        vec2 tmpVec(*this);
        tmpVec.x = this->x * i;
        tmpVec.y = this->y * i;
        return tmpVec;
    }
    friend vec2 operator*(float f, vec2 vec)
    {
        vec2 tmpVec(vec);
        tmpVec.x = vec.x * f;
        tmpVec.y = vec.y * f;
        return tmpVec;
    }
    vec2& operator*=(const vec2& vec)
    {
        return this->multiply(vec);
    }
    vec2& operator*=(const float i)
    {
        return this->multiply(i);
    }
// Division
    vec2 operator/(const vec2& vec)
    {
        vec2 tmpVec(*this);
        tmpVec.x =  this->x / vec.x;
        tmpVec.y = this->y / vec.y;
        return tmpVec;
    }
    vec2 operator/(const float f)
    {
        vec2 tmpVec(*this);
        tmpVec.x = this->x / f;
        tmpVec.y = this->y / f;
        return tmpVec;
    }
    friend vec2 operator/(const float f, vec2 vec)
    {
        vec2 tmpVec(vec);
        tmpVec.x = f / vec.x;
        tmpVec.y = f / vec.y;
        return tmpVec;
    }
    vec2& operator/=(const vec2& vec)
    {
        return this->divide(vec);
    }
// Equality
    bool operator==(const vec2& vec)
    {
        if(this->x == vec.x && this->y == vec.y)
            return true;
        return false;
    }
    
    bool operator!=(const vec2& vec)
    {
        return !(*this == vec);
    }
// Assignment
    vec2& operator=(const vec2& vec)
    {
        if(*this != vec)
        {
            this->x = vec.x;
            this->y = vec.y;
        }
        return *this;
    }
// IOstream
    friend std::ostream& operator<<(std::ostream& os, const vec2& vec)
    {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};

#endif