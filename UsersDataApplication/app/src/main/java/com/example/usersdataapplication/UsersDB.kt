package com.example.usersdataapplication

object UsersDB {

    external fun createUser(name: String?, balance: Float): UserData?

    external fun printUserData(user: UserData?): String?

    external fun addBalance(valueToBeAdded: Float, user: UserData?)

    external fun removeBalance(valueToBeSubtracted: Float, user: UserData?)
}