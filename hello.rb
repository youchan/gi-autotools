require "gi"

Hello = GI.load("Hello")

Hello::Greeting.new.message("hello")
