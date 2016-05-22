#ifndef APPM_MAT4_H_
#define APPM_MAT4_H_
/*
 * Uses Column - Major ordering
 * Another way to specify 2D array in just a single array
 * [row + col * 4]
 *
 * Rows: Align elements horizontally 
 * Columns: Align elements vertically
 */

#include "../vector/vec4.h"

struct mat4
{
    union
    {
        float elements[16] = {};
        vec4 columns[4];
    };
    
    mat4(){}
    
    mat4(float diagonal)
    {
        elements[0 + 0 * 4] = diagonal;
        elements[1 + 1 * 4] = diagonal;
        elements[2 + 2 * 4] = diagonal;
        elements[3 + 3 * 4] = diagonal;
    }
    
	mat4(const mat4& rhs)
	{
		for (int i = 0; i < 16; i++)
			this->elements[i] = rhs.elements[i];
	}
    
    static mat4 identity()
    {
        return mat4(1.0f);
    }
// Orthographic Matrix
    static mat4 orthographic(float left, float right, float bottom, float top, float near, float far)
    {
        mat4 result(1.0f);
        
        // Diagonals
        result.elements[0 + 0 * 4] = 2.0f / (right - left);
        result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
        result.elements[2 + 2 * 4] = 2 / (far - near);
        // Horizontals of last column
        result.elements[0 + 3 * 4] = -1 * ((right + left) / (right - left));
        result.elements[1 + 3 * 4] = -1 * ((top + bottom) / (top - bottom));
        result.elements[2 + 3 * 4] = -1 * ((far + near) / (far - near));
        
        return result;
    }
// Perspective Matrix
    static mat4 perspective(float fov, float aspectRatio, float near, float far)
    {
        mat4 result(1.0f);
        float t = Rads(tanf(0.5f * fov));
        
        result.elements[0 + 0 * 4] = 1 / (aspectRatio * t);
        result.elements[1 + 1 * 4] = 1 / t;
        result.elements[2 + 2 * 4] = -1 * ((far + near) / (far - near));
        result.elements[2 + 3 * 4] = -1 * ((2 * far * near) / (far - near));
        result.elements[3 + 2 * 4] = -1;
        result.elements[3 + 3 * 4] = 0;
        
        return result;
    }
    
// Translation
    static mat4 translation(const vec3& translation)
    {
        mat4 result(1.0f);
        
        result.elements[0 + 3 * 4] = translation.x;
        result.elements[1 + 3 * 4] = translation.y;
        result.elements[2 + 3 * 4] = translation.z;
        
        return result;
    }

// Scale
    static mat4 scale(const vec3& scale)
    {
        mat4 result(1.0f);
        
        result.elements[0 + 0 * 4] = scale.x;
        result.elements[1 + 1 * 4] = scale.y;
        result.elements[2 + 2 * 4] = scale.z;
        
        return result;
    }
    
// Rotation
    static mat4 rotation(const float angle, const vec3& axis)
    {
        mat4 result(1.0f);
        
        float radians = Rads(angle);
        float c = cos(radians);
        float s = sin(radians);
        float omc = 1.0f - c;
        
        float x = axis.x;
        float y = axis.y;
        float z = axis.z;
        
        result.elements[0 + 0 * 4] = x * x * omc + c;           //x rotation
        result.elements[1 + 0 * 4] = y * x * omc + z * s;       //y rotation
        result.elements[2 + 0 * 4] = x * z * omc - y * s;       //z rotation
        
        result.elements[0 + 1 * 4] = x * y * omc - z * s;       //x rotation
        result.elements[1 + 1 * 4] = y * y * omc + c;           //y rotation
        result.elements[2 + 1 * 4] = y * z * omc + x * s;       //z rotation

        result.elements[0 + 2 * 4] = x * z * omc + y * s;       //x rotation
        result.elements[1 + 2 * 4] = y * z * omc - x * s;       //y rotation
        result.elements[2 + 2 * 4] = z * z * omc + c;           //z rotation
        
        return result;
    }
    
// Matrix Multiplication
    mat4& multiply(const mat4& rhs)
    {
		float data[16];

        for(int y = 0; y < 4; y++)
        {
            for(int x = 0; x < 4; x++)
            {
                float sum = 0.0f;
                for(int e = 0; e < 4; e++)
                {
                    sum += this->elements[x + e * 4] * rhs.elements[e + y * 4];
                }
                //this->elements[x + y * 4] = sum;
				data[x + y * 4] = sum;
            }
        }
		memcpy(elements, data, 16 * 4);
        return *this;
    }
    
    mat4& operator*=(const mat4& rhs)
    {
        
        return this->multiply(rhs);
    }
    
    mat4 operator*(const mat4& rhs)
    {
        mat4 tmp(*this);
        return tmp.multiply(rhs);
    }
    
    float operator[](const int i)
    {
        if(i < 16 && i > -1)
            return this->elements[i];
        return 0.0f;
    }

	mat4& operator=(const mat4& rhs)
	{
		for (int i = 0; i < 16; i++)
			this->elements[i] = rhs.elements[i];
		return *this;
	}
    
    friend std::ostream& operator<<(std::ostream& os, const mat4& mat)
    {
        for(int i = 0; i < 4; i++)
        {
            os << "[\t";
            for(int j = 0; j < 4; j++)
            {
                os <<  mat.elements[i + j * 4] << "\t";
            }
            os << "]\n";
        }
        
        return os;
    }
};

#endif