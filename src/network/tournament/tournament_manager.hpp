//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2021 SuperTuxKart-Team
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 3
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef TOURNAMENT_MANAGER_HPP
#define TOURNAMENT_MANAGER_HPP

#include "network/remote_kart_info.hpp"
#include "utils/log.hpp"
#include "utils/string_utils.hpp"

#include <map>
#include <set>
#include <string>

class TournamentManager
{
private:
    std::map<std::string, std::string> m_player_teams; // m_player_teams[player1] = "A"
    std::string m_red_team; // "A"
    std::string m_blue_team; // "B"
    std::set<std::string> m_red_players;
    std::set<std::string> m_blue_players;

public:
    TournamentManager();
    virtual ~TournamentManager();

    void InitializePlayersAndTeams(std::string config_string, std::string red_team, std::string blue_team);
    void UpdateTeams(std::string red_team, std::string blue_team);
    std::string GetTeam(std::string player_name);
    KartTeam GetKartTeam(std::string player_name) const;
    void SetKartTeam(std::string player_name, KartTeam team);
    bool CanPlay(std::string player_name) const;
};

#endif