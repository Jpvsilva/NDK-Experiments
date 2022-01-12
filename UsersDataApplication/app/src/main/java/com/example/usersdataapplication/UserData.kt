package com.example.usersdataapplication

class UserData {
    var name: String? = null
    var balance = 0f

    override fun toString(): String {
        return "Name: $name, Balance: $balance;\n"
    }
}