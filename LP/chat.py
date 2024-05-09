from nltk.chat.util import Chat, reflections
import webbrowser

pairs = [
    [
        r"Hello|Hi|Hey",    
        ["Hi, how are you today? "]
    ],
    [
        r"I'm fine", 
        ["Glad to hear that, how can I help you? "]
    ],
    [
        r"who are you", 
        ["I am an AI assistant."]
    ],
    [
        r"What is your name ?",
        ["My name is ChatBot."]
    ],
    [
        r"What is your work ?",
        ["I assist people in their work."]
    ],
    [
        r"That's great!",
        ["Thanks!"]
    ],
    [
        r"open youtube",
        ["Opening YouTube..."]
    ],
    [
        r"Bye",
        ["Have a nice day!"]
    ]
]

def chatbot(user_input):
    chat = Chat(pairs=pairs, reflections=reflections)
    response = chat.respond(user_input)
    return response

def open_youtube():
    webbrowser.open("https://www.youtube.com")

def main():
    print("Welcome! Ask me anything or say bye to exit.")
    
    while True:
        user_input = input("You: ")
        if user_input.lower() == 'open youtube':
            open_youtube()
            print("Bot: Opening YouTube...")
        elif user_input.lower() == 'bye':
            print("Bot: Have a nice day!")
            break
        else:
            response = chatbot(user_input)
            print("Bot:", response)

if __name__ == "__main__":
    main()
