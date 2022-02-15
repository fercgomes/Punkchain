#include <boost/asio.hpp>
#include <ctime>
#include <iostream>
#include <string>

using boost::asio::ip::tcp;

std::string make_daytime_string()
{
    std::time_t now = std::time(nullptr);
    return std::ctime(&now);
}

int main()
{
    std::cout << "Server" << std::endl;

    try
    {
        boost::asio::io_context io_context;
        tcp::acceptor           acceptor(io_context, tcp::endpoint(tcp::v4(), 5000));

        for (;;)
        {
            tcp::socket socket(io_context);
            acceptor.accept(socket);

            std::string message = make_daytime_string();

            boost::system::error_code ignored_error;
            boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}