# Rock Paper Scissors Game Simulator
This is a C++ implementation of a rock paper scissors game where multiple computer strategies compete in a tournament format.

The main program sets up a tournament between various computer strategies:
- Each streategy is represented by a class that defines how it selects moves.
- The tournament runs multiple rounds and determines the overall winner.

## Strategies Included
- **Avalanche**: Always plays 'Rock'.
- **Bureaucrat**: Always plays 'Paper'.
- **Cresendo**: Cycles through 'Paper', 'Scissors', 'Rock'.
- **FistfullODollars**: Plaus 'Rock', 'Paper', 'Paper' in a repeating pattern.
- **PaperDoll**: Plays 'Paper', 'Scissors', 'Scissors' in a repeating pattern.
**RandomComputer** Randomly chooses between 'Rock', 'Paper', and 'Scissors'.
**Toolbox**: Always plays 'Scissors'.

## Future Improvements
- Add a graphical user interface.
- Allow users to input custom strategies.