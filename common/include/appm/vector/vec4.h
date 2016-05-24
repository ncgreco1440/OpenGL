/*************************************************************************
 * vec4 struct
 *
 * struct for vectors that contain an x, y, z, and w component
 *
 *************************************************************************/
#ifndef APPM_VEC4_H_
#define APPM_VEC4_H_

struct vec4
{
/*************************************************************************
 * Data Members
 *************************************************************************/
    union { float x; float r; float s; };
    union { float y; float g; float t; };
    union { float z; float b; float p; };
    union { float w; float a; float q; };
    //float x, y, z, w;
/*************************************************************************
 * Constructors
 *************************************************************************/
    vec4()
    {
        this->x = 0.0f;
        this->y = 0.0f;
        this->z = 0.0f;
        this->w = 1.0f;
    }
// Explicit Type Conversion vec2 to vec4
    explicit vec4(const vec2& vec)
    {
        this->x = vec.x;
        this->y = vec.y;
        this->z = 0.0f;
        this->w = 1.0f;
    }
    
// Explicit Type Conversion vec3 to vec4
    explicit vec4(const vec3& vec)
    {
        this->x = vec.x;
        this->y = vec.y;
        this->z = vec.z;
        this->w = 1.0f;
    }
    
    explicit vec4(const vec2& vec, const float z = 0.0f, const float w = 1.0f)
    {
        this->x = vec.x;
        this->y = vec.y;
        this->z = z;
        this->w = w;
    }
    
    explicit vec4(const vec3& vec, const float w = 1.0f)
    {
        this->x = vec.x;
        this->y = vec.y;
        this->z = vec.z;
        this->w = w;
    }

    
    vec4(const vec4& vec)
    {
        this->x = vec.x;
        this->y = vec.y;
        this->z = vec.z;
        this->w = vec.w;
    }
    
    vec4(const float x, const float y, const float z = 0.0f, const float w = 1.0f)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }
/*************************************************************************
 * Base Arithmetic Functions
 *************************************************************************/
// Addition
    vec4& add(const vec4& rhs)
    {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;
        this->w += rhs.w;
        return *this;
    }
    
    vec4& add(const float i)
    {
        this->x += i;
        this->y += i;
        this->z += i;
        this->w += i;
        return *this;
    }
    
    vec4& add(const float x, const float y, const float z = 0.0f, const float w = 0.0f)
    {
        this->x += x;
        this->y += y;
        this->z += z;
        this->w += w;
        return *this;
    }
//Addition w/ vec2
    vec4& add(const vec2& vec, const float z = 0.0f, const float w = 0.0f)
    {
        this->x += vec.x;
        this->y += vec.y;
        this->z += z;
        this->w += w;
        return *this;
    }
    
//Addition w/ vec3
    vec4& add(const vec3& vec, const float w = 0.0f)
    {
        this->x += vec.x;
        this->y += vec.y;
        this->z += vec.z;
        this->w += w;
        return *this;
    }

    
// Subtraction
    vec4& subtract(const vec4& rhs)
    {
        this->x -= rhs.x;
        this->y -= rhs.y;
        this->z -= rhs.z;
        this->w -= rhs.w;
        return *this;
        
    }
    
    vec4& subtract(const float i)
    {
        this->x -= i;
        this->y -= i;
        this->z -= i;
        this->w -= i;
        return *this;
    }
    
    vec4& subtract(const float x, const float y, const float z = 0.0f, const float w = 0.0f)
    {
        this->x -= x;
        this->y -= y;
        this->z -= z;
        this->w -= w;
        return *this;
    }
// Subtraction w/ vec2
    vec4& subtract(const vec2& vec, const float z = 0.0f, const float w = 0.0f)
    {
        this->x -= vec.x;
        this->y -= vec.y;
        this->z -= z;
        this->w -= w;
        return *this;
    }
    
// Subtraction w/ vec3
    vec4& subtract(const vec3& vec, const float w = 0.0f)
    {
        this->x -= vec.x;
        this->y -= vec.y;
        this->z -= vec.z;
        this->w -= w;
        return *this;
    }
    
// Multiplication
    vec4& multiply(const vec4& rhs)
    {
        this->x *= rhs.x;
        this->y *= rhs.y;
        this->z *= rhs.z;
        this->w *= rhs.w;
        return *this;
    }
    
    vec4& multiply(const float i)
    {
        this->x *= i;
        this->y *= i;
        this->z *= i;
        this->w *= i;
        return *this;
    }
    
    vec4& multiply(const float x, const float y, const float z = 1.0f, const float w = 1.0f)
    {
        this->x *= x;
        this->y *= y;
        this->z *= z;
        this->w *= w;
        return *this;
    }

// Multiplying w/ vec2
    vec4& multiply(const vec2& vec, const float z = 1.0f, const float w = 1.0f)
    {
        this->x *= vec.x;
        this->y *= vec.y;
        this->z *= z;
        this->w *= w;
        return *this;
    }
    
// Multiplying w/ vec3
    vec4& multiply(const vec3& vec, const float w = 1.0f)
    {
        this->x *= vec.x;
        this->y *= vec.y;
        this->z *= vec.z;
        this->w *= w;
        return *this;
    }
    
// Division
    vec4& divide(const vec4& rhs)
    {
        this->x /= rhs.x;
        this->y /= rhs.y;
        this->z /= rhs.z;
        this->w /= rhs.w;
        return *this;
    }
    
    vec4& divide(const float i)
    {
        this->x /= i;
        this->y /= i;
        this->z /= i;
        this->w /= i;
        return *this;
    }
    
    vec4& divide(const float x, const float y, const float z = 1.0f, const float w = 1.0f)
    {
        this->x /= x;
        this->y /= y;
        this->z /= z;
        this->w /= w;
        return *this;
    }
    
// Divide w/ vec2
    vec4& divide(const vec2& vec, const float z = 1.0f, const float w = 1.0f)
    {
        this->x /= vec.x;
        this->y /= vec.y;
        this->z /= z;
        this->w /= w;
        return *this;
    }
    
// Divide w/ vec3
    vec4& divide(const vec3& vec, const float w = 1.0f)
    {
        this->x /= vec.x;
        this->y /= vec.y;
        this->z /= vec.z;
        this->w /= w;
        return *this;
    }
/*************************************************************************
 * Operator Overloading
 *************************************************************************/
// Addition
    vec4 operator+(const vec4& vec)
    {
        vec4 tmpVec(*this);
        tmpVec.x = this->x + vec.x;
        tmpVec.y = this->y + vec.y;
        tmpVec.z = this->z + vec.z;
        tmpVec.w = this->w + vec.w;
        return tmpVec;
    }
    vec4 operator+(const float& i)
    {
        vec4 tmpVec(*this);
        tmpVec.x = this->x + i;
        tmpVec.y = this->y + i;
        tmpVec.z = this->z + i;
        tmpVec.w = this->w + i;
        return tmpVec;
    }
    friend vec4 operator+(float i, vec4& vec)
    {
        vec4 tmpVec(vec);
        tmpVec.x = i + vec.x;
        tmpVec.y = i + vec.y;
        tmpVec.z = i + vec.z;
        tmpVec.w = i + vec.w;
        return tmpVec;
    }
    vec4& operator+=(const vec4& vec)
    {
        return this->add(vec);
    }
    vec4& operator+=(const float i)
    {
        return this->add(i);
    }
    vec4& operator++()
    {
        this->x++;
        this->y++;
        this->z++;
        this->w++;
        return *this;
    }
    vec4 operator++(int i)
    {
        vec4 tmpVec(*this);
        this->x++;
        this->y++;
        this->z++;
        this->w++;
        return tmpVec;
    }
// Addition w/ vec2
    vec4 operator+(const vec2& vec)
    {
        vec4 tmpVec(*this);
        tmpVec.x += vec.x;
        tmpVec.y += vec.y;
        return tmpVec;
    }
    friend vec4 operator+(const vec2& v2, const vec4& v4)
    {
        vec4 tmpVec(v4);
        tmpVec.x += v2.x;
        tmpVec.y += v2.y;
        return tmpVec;
    }
    vec4 operator+=(const vec2& vec)
    {
        return this->add(vec);
    }
// Addition w/ vec3
    vec4 operator+(const vec3& vec)
    {
        vec4 tmpVec(*this);
        tmpVec.x += vec.x;
        tmpVec.y += vec.y;
        tmpVec.z += vec.z;
        return tmpVec;
    }
    friend vec4 operator+(const vec3& v3, const vec4& v4)
    {
        vec4 tmpVec(v4);
        tmpVec.x += v3.x;
        tmpVec.y += v3.y;
        tmpVec.z += v3.z;
        return tmpVec;
    }
    vec4 operator+=(const vec3& vec)
    {
        return this->add(vec);
    }
// Subtraction
    vec4 operator-(const vec4& vec)
    {
        vec4 tmpVec(vec);
        tmpVec.x = this->x - vec.x;
        tmpVec.y = this->y - vec.y;
        tmpVec.z = this->z - vec.z;
        tmpVec.w = this->w - vec.w;
        return tmpVec;
    }
    vec4 operator-(const float i)
    {
        vec4 tmpVec(*this);
        tmpVec.x = this->x - i;
        tmpVec.y = this->y - i;
        tmpVec.z = this->z - i;
        tmpVec.w = this->w - i;
        return tmpVec;
    }
    friend vec4 operator-(float i, vec4& vec)
    {
        vec4 tmpVec(vec);
        tmpVec.x = i - vec.x;
        tmpVec.y = i - vec.y;
        tmpVec.z = i - vec.z;
        tmpVec.w = i - vec.w;
        return tmpVec;
    }
    vec4& operator-=(const vec4& vec)
    {
        return this->subtract(vec);
    }
    vec4& operator-=(const float i)
    {
        return this->subtract(i);
    }
    vec4& operator--()
    {
        this->x--;
        this->y--;
        this->z--;
        this->w--;
        return *this;
    }
    vec4 operator--(int)
    {
        vec4 tmpVec(*this);
        this->x--;
        this->y--;
        this->z--;
        this->w--;
        return tmpVec;
    }
// Subtracting w/ vec2
    vec4 operator-(const vec2& vec)
    {
        vec4 tmpVec(*this);
        tmpVec.x -= vec.x;
        tmpVec.y -= vec.y;
        return tmpVec;
    }
    vec4 operator-=(const vec2& vec)
    {
        return this->subtract(vec);
    }
    friend vec4 operator-(const vec2& v2, const vec4& v4)
    {
        vec4 tmpVec(v4);
        tmpVec.x = v2.x - tmpVec.x;
        tmpVec.y = v2.y - tmpVec.y;
        return tmpVec;
    }
// Subtracting w/ vec3
    vec4 operator-(const vec3& vec)
    {
        vec4 tmpVec(*this);
        tmpVec.x -= vec.x;
        tmpVec.y -= vec.y;
        tmpVec.z -= vec.z;
        return tmpVec;
    }
    vec4 operator-=(const vec3& vec)
    {
        return this->subtract(vec);
    }
    friend vec4 operator-(const vec3& v3, const vec4& v4)
    {
        vec4 tmpVec(v4);
        tmpVec.x = v3.x - tmpVec.x;
        tmpVec.y = v3.y - tmpVec.y;
        tmpVec.z = v3.z - tmpVec.z;
        return tmpVec;
    }
// Multiplication
    vec4 operator*(const vec4& vec)
    {
        vec4 tmpVec(*this);
        tmpVec.x = this->x * vec.x;
        tmpVec.y = this->y * vec.y;
        tmpVec.z = this->z * vec.z;
        tmpVec.w = this->w * vec.w;
        return tmpVec;
    }
    vec4 operator*(const float i)
    {
        vec4 tmpVec(*this);
        tmpVec.x = this->x * i;
        tmpVec.y = this->y * i;
        tmpVec.z = this->z * i;
        tmpVec.w = this->w * i;
        return tmpVec;
    }
    friend vec4 operator*(float f, vec4 vec)
    {
        vec4 tmpVec(vec);
        tmpVec.x = vec.x * f;
        tmpVec.y = vec.y * f;
        tmpVec.z = vec.z * f;
        tmpVec.w = vec.w * f;
        return tmpVec;
    }
    vec4& operator*=(const vec4& vec)
    {
        return this->multiply(vec);
    }
    vec4& operator*=(const float i)
    {
        return this->multiply(i);
    }
// Multiplying w/ vec2
    vec4 operator*(const vec2& vec)
    {
        vec4 tmpVec(*this);
        tmpVec.x *= vec.x;
        tmpVec.y *= vec.y;
        return tmpVec;
    }
    vec4 operator*=(const vec2& vec)
    {
        return this->multiply(vec);
    }
    friend vec4 operator*(const vec2& v2, const vec4& v4)
    {
        vec4 tmpVec(v4);
        tmpVec.x *= v2.x;
        tmpVec.y *= v2.y;
        return tmpVec;
    }
// Multiplying w/ vec3
    vec4 operator*(const vec3& vec)
    {
        vec4 tmpVec(*this);
        tmpVec.x *= vec.x;
        tmpVec.y *= vec.y;
        tmpVec.z *= vec.z;
        return tmpVec;
    }
    vec4 operator*=(const vec3& vec)
    {
        return this->multiply(vec);
    }
    friend vec4 operator*(const vec3& v3, const vec4& v4)
    {
        vec4 tmpVec(v4);
        tmpVec.x *= v3.x;
        tmpVec.y *= v3.y;
        tmpVec.z *= v3.z;
        return tmpVec;
    }
// Division
    vec4 operator/(const vec4& vec)
    {
        vec4 tmpVec(*this);
        tmpVec.x =  this->x / vec.x;
        tmpVec.y = this->y / vec.y;
        tmpVec.z = this->z / vec.z;
        tmpVec.w = this->w / vec.w;
        return tmpVec;
    }
    vec4 operator/(const float f)
    {
        vec4 tmpVec(*this);
        tmpVec.x = this->x / f;
        tmpVec.y = this->y / f;
        tmpVec.z = this->z / f;
        tmpVec.w = this->w / f;
        return tmpVec;
    }
    friend vec4 operator/(const float f, vec4 vec)
    {
        vec4 tmpVec(vec);
        tmpVec.x = f / vec.x;
        tmpVec.y = f / vec.y;
        tmpVec.z = f / vec.z;
        tmpVec.w = f / vec.w;
        return tmpVec;
    }
    vec4& operator/=(const vec4& vec)
    {
        return this->divide(vec);
    }
// Dividing w/ vec2
    vec4 operator/(const vec2& vec)
    {
        vec4 tmpVec(*this);
        tmpVec.x /= vec.x;
        tmpVec.y /= vec.y;
        return tmpVec;
    }
    vec4 operator/=(const vec2& vec)
    {
        return this->divide(vec);
    }
    friend vec4 operator/(const vec2& v2, const vec4& v4)
    {
        vec4 tmpVec(v4);
        tmpVec.x = v2.x / tmpVec.x;
        tmpVec.x = v2.y / tmpVec.y;
        return tmpVec;
    }
    // Multiplying w/ vec3
    vec4 operator/(const vec3& vec)
    {
        vec4 tmpVec(*this);
        tmpVec.x /= vec.x;
        tmpVec.y /= vec.y;
        tmpVec.z /= vec.z;
        return tmpVec;
    }
    vec4 operator/=(const vec3& vec)
    {
        return this->multiply(vec);
    }
    friend vec4 operator/(const vec3& v3, const vec4& v4)
    {
        vec4 tmpVec(v4);
        tmpVec.x = v3.x / tmpVec.x;
        tmpVec.y = v3.y / tmpVec.y;
        tmpVec.z = v3.z / tmpVec.z;
        return tmpVec;
    }
/*************************************************************************
 * Equality
 *************************************************************************/
    bool operator==(const vec4& vec) const
    {
		return this->x == vec.x && this->y == vec.y && this->z == vec.z && this->w == vec.w;
    }
    
    bool operator!=(const vec4& vec) const
    {
        return !(*this == vec);
    }
/*************************************************************************
 * Assignment
 *************************************************************************/
    vec4& operator=(const vec4& vec)
    {
        if(this != &vec)
        {
            this->x = vec.x;
            this->y = vec.y;
            this->z = vec.z;
            this->w = vec.w;
        }
        return *this;
    }
/*************************************************************************
 * IOstream
 *************************************************************************/
    friend std::ostream& operator<<(std::ostream& os, const vec4& vec)
    {
        os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w <<  ")";
        return os;
    }
};

#endif