# Development
-----------------------------------
### -Week 1-
----------------
-List of tasks I want to achieve by the end of this working week-
- [x] Download the libraries and frameworks I want to use
- [x] make sure I can get them working properly
- [ ] Try out test examples for these libraries such as:
 - accessing and opening the MacBook camera
 
- beginning to develop the facial detection program

- using the dlib library to find and detect facial features/structures

- figuring out the object I want to use to test the filter

### -Week 2-
----------------
-Summary-

As I began working on my facial filter, I realized it was much more difficult than I thought. I first struggled with even getting the project to compile. There were a lot of errors I was getting that I had no clue how to fix, so I had to do a lot of research into pretty much all the addons and what they did. This helped me understand what addons I exactly needed to include in my final project. Accessing the camera however, was something I did manage to make a bit of progress on, since I found an OF example that did just that. So for this week I completed how to implement the addons on OpenFrameworks. However, if the entirity of the project seems too difficult to complete, I've decided I want to create my rendition of Pac-Man, since I can work somewhat similarly to how the OF Snake project functioned. This is my plan in case I am unable to develop my face filter program.

-Progress Made This Week-
- found example to base video capturing on
- researched more on implementing face filters in cpp
- set up files for video capture

-List of tasks I want to achieve by the end of this working week-
- [x] Access the Camera using ofxAVFVideoRecorder
- [x] Understand code that I am implementing from example project
- [x] Further research into face filter development in cpp.
- [ ] Attempt to use dlib

### -Week 3/4-
----------------
-Summary-

Within the final weeks I achieved the intended goal of my project. Through thorough research into face tracking within OpenFrameworks, I discovered the library OfxCv. This library allowed me to easily track a face in real time on the webcam using a finder object that it includes. However, I was unable to successfully implement my planned extension of adding different color filters for the webcam. This proved too difficult, as I could not completely figure out how to link the camera pixels with a key pressed. I did figure out how to implement screenshots though, and have them be saved to the data folder within the bin.

-Progress made this week-
- got the camera to track a face and place the mustache on it
- implemented screenshotting
- implemented libraries correctly

-Additional Comments-

I was not sure how to completely develop testing for my project, as it does not implement many testable features. However, if I did manage to figure out the tests, they would probably look something like me placing the mustache on an image and saving it, and checking if it was correct based on where the face tracker would've put it.
