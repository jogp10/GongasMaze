T02_G11
João de Oliveira Gigante Pinheiro
José Luís Barbosa de Araújo

PROGRAM DEVELOPMENT STATE:

// (say here if all the objectives were accomplished or, otherwise, which ones were not achieved, and also what improvements were made, 
// if any)

When it comes to all the objectives and expectations we had for this project, we believe and can firmly say that we exceeded our 
expectations and accomplished all the objectives we had planned. Of course we thought we could go a little further when it comes to 
tweaks and little things we could add to make the program better, but we were afraid we would just go a bit off-topic by doing 
some of this things so we just kept it simple. Some of the tweaks we briefly thought about were, for example, generating a map 
automatically with the robots being placed randomly across the map.   

Whilst in the debugging phase, we noticed we could change some things a little. One example of this things were substituting an 
implementation   

MAIN DIFFICULTIES:

// (describe here the main difficulties that you faced when developping the program)

When trying to write a new register into the leaderboard and put it in order, we had some troubles.
We understood we just couldn't write in a file directly anywhere we needed, so we had to get around it. How?
We opened the leaderboard file and then wrote the time we wanted to register at the end of it. Afterwards we used getline command to 
store all lines of the file in a dynamic vector that we sorted later. After sorting this vector based on the time each player took to 
defeat all the robots, we used a for loop to write all the lines back in the leaderboard file. 

When we thought we had finished almost everything, we started testing our program a little more in depth. Not only did we 
stumble upon some bugs but also found some "bad practises" we were commiting, such as not using a header file. Most of the bugs we 
found were related to the gameplay. For example, as the player moved we couldn't make the AI robots move as they should, sometimes
after the play a robot would hit another robot and things weren't working properly as they should and that was shutting down the 
execution of the program unexpectedly and so on. We can say that, unsurprisingly, we spent a vast majority of the time debugging
and trying to find a smarter and more efficient way of redoing things so that some bugs didn't occur.



