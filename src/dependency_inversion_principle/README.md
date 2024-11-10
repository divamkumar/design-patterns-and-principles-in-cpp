## Dependency Injection
Dependency injection is a fancy way of saying that if your code depends on something else, you pass it in instead of coding the dependency into your thing.

### Link to Source
(YouTube video)[https://www.youtube.com/watch?app=desktop&v=J1f5b4vcxCQ]

### Case Study
Building a business app where users can chat with their coworkers. They can also send pictures and files to each other.
- If a user sends a file, it gets sent separately through the chat service for instantaneous send/receive.
- If a user sends a file, the file gets uploaded to the attachment service, which is responsible for storing, retrieving, and processing attachments.
  - Default storage is Amazon S3
  - However, since a few of our clients do not want to 
