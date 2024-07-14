# Intro
It is now the time to explore ROS communication features.
At the end of this section you will be able to make your nodes communicate between each other, using ROS2 Topics.

Here’s what you’ll do in this section:
- Understand what is a ROS2 topic thanks to a real life analogy
- Write your own Topic (publisher/subscriber) in both Python and Cpp
- Debug topics with ROS2 tools
- Experiment on Turtlesim
And finally, you’ll work on an activity to practice on everything you’ve seen until this point.

And now, what is a ROS2 Topic?
# Topics
## View Example MSG type
```bash
ros2 interface show example_interfaces/msg/String
```
## View Topic List
```bash
ros2 topic list
```

## View Topic Info
```bash
ros2 topic info /<topic_name>
```

## Echo Topic
To see the messages being published to a topic, you can use the following command:
```bash
ros2 topic echo /<topic_name>
```
