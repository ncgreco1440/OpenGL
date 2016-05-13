/*************************************************************************
 * vec3 struct
 *
 * struct for vectors that contain an x, y, and z component
 *
 *************************************************************************/
#ifndef APPM_VEC3_H_
#define APPM_VEC3_H_

struct vec3
{
/*************************************************************************
 * Data Members
 *************************************************************************/
    float x, y, z;
/*************************************************************************
 * Constructors
 *************************************************************************/
    vec3()
    {
        this->x = 0.0f;
        this->y = 0.0f;
        this->z = 0.0f;
    }
// Explicit Type Conversion
    explicit vec3(const vec2& vec)
    {
        this->x = vec.x;
        this->y = vec.y;
        this->z = 0.0f;
    }
    
    explicit vec3(const vec2& vec, const float z)
    {
        this->x = vec.x;
        this->y = vec.y;
        this->z = z;
    }
    
    vec3(const vec3& vec)
    {
        this->x = vec.x;
        this->y = vec.y;
        this->z = vec.z;
    }
    
    vec3(const float x, const float y, const float z = 0.0f)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
/*************************************************************************
 * Base Arithmetic Functions
 *************************************************************************/
// Addition
    vec3& add(const vec3& rhs)
    {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;
        return *this;
    }
    
    vec3& add(const float i)
    {
        this->x += i;
        this->y += i;
        this->z += i;
        return *this;
    }
    
    vec3& add(const float x, const float y, const float z = 0)
    {
        this->x += x;
        this->y += y;
        this->z += z;
        return *this;
    }
    
// Addition w/ vec2
    vec3& add(const vec2& vec)
    {
        this->x += vec.x;
        this->y += vec.y;
        return *this;
    }
    
    vec3& add(const vec2& vec, const float z)
    {
        this->x += vec.x;
        this->y += vec.y;
        this->z += z;
        return *this;
    }

// Subtraction
    vec3& subtract(const vec3& rhs)
    {
        this->x -= rhs.x;
        this->y -= rhs.y;
        this->z -= rhs.z;
        return *this;
        
    }
    
    vec3& subtract(const float i)
    {
        this->x -= i;
        this->y -= i;
        this->z -= i;
        return *this;
    }
    
    vec3& subtract(const float x, const float y, const float z = 0)
    {
        this->x -= x;
        this->y -= y;
        this->z -= z;
        return *this;
    }
    
// Substraction w/ vec2
    vec3& subtract(const vec2& vec)
    {
        this->x -= vec.x;
        this->y -= vec.y;
        return *this;
    }
    vec3& subtract(const vec2& vec, const float z)
    {
        this->x -= vec.x;
        this->y -= vec.y;
        this->z -= z;
        return *this;
    }

// Multiplication
    vec3& multiply(const vec3& rhs)
    {
        this->x *= rhs.x;
        this->y *= rhs.y;
        this->z *= rhs.z;
        return *this;
    }
    
    vec3& multiply(const float i)
    {
        this->x *= i;
        this->y *= i;
        this->z *= i;
        return *this;
    }
    
    vec3& multiply(const float x, const float y, const float z = 1)
    {
        this->x *= x;
        this->y *= y;
        this->z *= z;
        return *this;
    }
    
// Multiply w/ vec2
    vec3& multiply(const vec2& vec)
    {
        this->x *= vec.x;
        this->y *= vec.y;
        return *this;
    }
    
    vec3& multiply(const vec2& vec, const float z)
    {
        this->x *= vec.x;
        this->y *= vec.y;
        this->z *= z;
        return *this;
        
    }
    
// Division
    vec3& divide(const vec3& rhs)
    {
        this->x /= rhs.x;
        this->y /= rhs.y;
        this->z /= rhs.z;
        return *this;
    }
    
    vec3& divide(const float i)
    {
        this->x /= i;
        this->y /= i;
        this->z /= i;
        return *this;
    }
    
    vec3& divide(const float x, const float y, const float z = 1)
    {
        this->x /= x;
        this->y /= y;
        this->z /= z;
        return *this;
    }
    
// Dividing w/ vec2
    vec3& divide(const vec2& vec)
    {
        this->x /= vec.x;
        this->y /= vec.y;
        return *this;
    }
    
    vec3& divide(const vec2& vec, const float z)
    {
        this->x /= vec.x;
        this->y /= vec.y;
        this->z /= z;
        return *this;
    }
/*************************************************************************
 * Operator Overloading
 *************************************************************************/
// Addition
    vec3 operator+(const vec3& vec)
    {
        vec3 tmpVec(*this);
        tmpVec.x = this->x + vec.x;
        tmpVec.y = this->y + vec.y;
        tmpVec.z = this->z + vec.z;
        return tmpVec;
    }
    vec3 operator+(const float& i)
    {
        vec3 tmpVec(*this);
        tmpVec.x = this->x + i;
        tmpVec.y = this->y + i;
        tmpVec.z = this->z + i;
        return tmpVec;
    }
    friend vec3 operator+(float i, vec3& vec)
    {
        vec3 tmpVec(vec);
        tmpVec.x = i + vec.x;
        tmpVec.y = i + vec.y;
        tmpVec.z = i + vec.z;
        return tmpVec;
    }
    vec3& operator+=(const vec3& vec)
    {
        return this->add(vec);
    }
    vec3& operator+=(const float i)
    {
        return this->add(i);
    }
    vec3& operator++()
    {
        this->x++;
        this->y++;
        this->z++;
        return *this;
    }
    vec3 operator++(int i)
    {
        vec3 tmpVec(*this);
        this->x++;
        this->y++;
        this->z++;
        return tmpVec;
    }
// Addition w/ vec2
    vec3 operator+(const vec2& vec)
    {
        vec3 tmpVec(*this);
        tmpVec.x += vec.x;
        tmpVec.y += vec.y;
        return tmpVec;
    }
    vec3 operator+=(const vec2& vec)
    {
        return this->add(vec);
    }
    friend vec3 operator+(const vec2& v2, const vec3& v3)
    {
        vec3 tmpVec(v3);
        tmpVec.x += v2.x;
        tmpVec.y += v2.y;
        return tmpVec;
    }
// Subtraction
    vec3 operator-(const vec3& vec)
    {
        vec3 tmpVec(vec);
        tmpVec.x = this->x - vec.x;
        tmpVec.y = this->y - vec.y;
        tmpVec.z = this->z - vec.z;
        return tmpVec;
    }
    vec3 operator-(const float i)
    {
        vec3 tmpVec(*this);
        tmpVec.x = this->x - i;
        tmpVec.y = this->y - i;
        tmpVec.z = this->z - i;
        return tmpVec;
    }
    friend vec3 operator-(float i, vec3& vec)
    {
        vec3 tmpVec(vec);
        tmpVec.x = i - vec.x;
        tmpVec.y = i - vec.y;
        tmpVec.z = i - vec.z;
        return tmpVec;
    }
    vec3& operator-=(const vec3& vec)
    {
        return this->subtract(vec);
    }
    vec3& operator-=(const float i)
    {
        return this->subtract(i);
    }
    vec3& operator--()
    {
        this->x--;
        this->y--;
        this->z--;
        return *this;
    }
    vec3 operator--(int)
    {
        vec3 tmpVec(*this);
        this->x--;
        this->y--;
        this->z--;
        return tmpVec;
    }
// Subtraction w/ vec2
    vec3 operator-(const vec2& vec)
    {
        vec3 tmpVec(*this);
        tmpVec.x -= vec.x;
        tmpVec.y -= vec.y;
        return tmpVec;
    }
    vec3 operator-=(const vec2& vec)
    {
        return this->subtract(vec);
    }
    friend vec3 operator-(const vec2& v2, const vec3& v3)
    {
        vec3 tmpVec(v3);
        tmpVec.x = v2.x - tmpVec.x;
        tmpVec.y = v2.y - tmpVec.y;
        return tmpVec;
    }
// Multiplication
    vec3 operator*(const vec3& vec)
    {
        vec3 tmpVec(*this);
        tmpVec.x = this->x * vec.x;
        tmpVec.y = this->y * vec.y;
        tmpVec.z = this->z - vec.z;
        return tmpVec;
    }
    vec3 operator*(const float i)
    {
        vec3 tmpVec(*this);
        tmpVec.x = this->x * i;
        tmpVec.y = this->y * i;
        tmpVec.z = this->z * i;
        return tmpVec;
    }
    friend vec3 operator*(float f, vec3 vec)
    {
        vec3 tmpVec(vec);
        tmpVec.x = vec.x * f;
        tmpVec.y = vec.y * f;
        tmpVec.z = vec.z * f;
        return tmpVec;
    }
    vec3& operator*=(const vec3& vec)
    {
        return this->multiply(vec);
    }
    vec3& operator*=(const float i)
    {
        return this->multiply(i);
    }
// Multiplication w/ vec2
    vec3 operator*(const vec2& vec)
    {
        vec3 tmpVec(*this);
        tmpVec.x *= vec.x;
        tmpVec.y *= vec.y;
        return tmpVec;
    }
    vec3 operator*=(const vec2& vec)
    {
        return this->multiply(vec);
    }
    friend vec3 operator*(const vec2& v2, const vec3& v3)
    {
        vec3 tmpVec(v3);
        tmpVec.x *= v2.x;
        tmpVec.y *= v2.y;
        return tmpVec;
    }
// Division
    vec3 operator/(const vec3& vec)
    {
        vec3 tmpVec(*this);
        tmpVec.x =  this->x / vec.x;
        tmpVec.y = this->y / vec.y;
        tmpVec.z = this->z / vec.z;
        return tmpVec;
    }
    vec3 operator/(const float f)
    {
        vec3 tmpVec(*this);
        tmpVec.x = this->x / f;
        tmpVec.y = this->y / f;
        tmpVec.z = this->z / f;
        return tmpVec;
    }
    friend vec3 operator/(const float f, vec3 vec)
    {
        vec3 tmpVec(vec);
        tmpVec.x = f / vec.x;
        tmpVec.y = f / vec.y;
        tmpVec.z = f / vec.z;
        return tmpVec;
    }
    vec3& operator/=(const vec3& vec)
    {
        return this->divide(vec);
    }
// Dividing w/ vec2
    vec3 operator/(const vec2& vec)
    {
        vec3 tmpVec(*this);
        tmpVec.x = this->x / vec.x;
        tmpVec.y = this->y / vec.y;
        return tmpVec;
    }
    vec3 operator/=(const vec2& vec)
    {
        return this->divide(vec);
    }
    friend vec3 operator/(const vec2& v2, const vec3& v3)
    {
        vec3 tmpVec(v3);
        tmpVec.x = v2.x / tmpVec.x;
        tmpVec.y = v2.y / tmpVec.y;
        return tmpVec;
    }
/*************************************************************************
 * Equality
 *************************************************************************/
    bool operator==(const vec3& vec) const
    {
        if(this->x == vec.x && this->y == vec.y && this->z == vec.z)
            return true;
        return false;
    }
    
    bool operator!=(const vec3& vec) const
    {
        return !(*this == vec);
    }
/*************************************************************************
 * Assignment
 *************************************************************************/
    vec3& operator=(const vec3& vec)
    {
        if(*this != vec)
        {
            this->x = vec.x;
            this->y = vec.y;
            this->z = vec.z;
        }
        return *this;
    }
/*************************************************************************
 * IOstream
 *************************************************************************/
    friend std::ostream& operator<<(std::ostream& os, const vec3& vec)
    {
        os << "(" << vec.x << ", " << vec.y << ", " << vec.z <<  ")";
        return os;
    }
};

#endif