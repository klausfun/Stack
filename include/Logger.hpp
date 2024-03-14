class Logger
{
public:
    Logger();

    Logger(const Logger& other);
    Logger(Logger&& other) noexcept;

    Logger& operator=(const Logger& other);
    Logger& operator=(Logger&& other) noexcept;

    ~Logger();
};
