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

#include "network/tournament/tournament_manager.hpp"

TournamentManager::TournamentManager()
{
}

TournamentManager::~TournamentManager()
{
}

// Format of config_string = "player1 A player2 A player3 B player4 B player5 Sub"
void TournamentManager::InitializePlayersAndTeams(std::string config_string, std::string red_team, std::string blue_team)
{
    std::vector<std::string> player_teams = StringUtils::split(config_string, ' ');
    if (player_teams.size() % 2 != 0)
    {
        Log::error("TournamentManager", "Invalid config string");
        return;
    }
        
    for (size_t i = 0; i < player_teams.size(); i += 2)
        m_player_teams[player_teams[i]] = player_teams[i + 1];

    UpdateTeams(red_team, blue_team);
}

void TournamentManager::UpdateTeams(std::string red_team, std::string blue_team)
{
    m_red_team = red_team;
    m_blue_team = blue_team;

    m_red_players.clear();
    m_blue_players.clear();
    for (auto& pt : m_player_teams)
    {
        if (pt.second == red_team)
            m_red_players.insert(pt.first);
        if (pt.second == blue_team)
            m_blue_players.insert(pt.first);
    }
}

std::string TournamentManager::GetTeam(std::string player_name)
{
    return (m_player_teams.find(player_name) == m_player_teams.end()) ? "" 
        : m_player_teams[player_name];
}

KartTeam TournamentManager::GetKartTeam(std::string player_name) const
{
    bool blue = m_blue_players.find(player_name) != m_blue_players.end();
    bool red = m_red_players.find(player_name) != m_red_players.end();

    return red ? KART_TEAM_RED : (blue ? KART_TEAM_BLUE : KART_TEAM_NONE);
}

void TournamentManager::SetKartTeam(std::string player_name, KartTeam team)
{
    switch (team)
    {
    case KART_TEAM_NONE:
        m_red_players.erase(player_name);
        m_blue_players.erase(player_name);
        return;
    case KART_TEAM_RED:
        m_red_players.insert(player_name);
        m_blue_players.erase(player_name);
        return;
    case KART_TEAM_BLUE:
        m_blue_players.insert(player_name);
        m_red_players.erase(player_name);
        return;
    }
}

bool TournamentManager::CanPlay(std::string player_name) const
{
    return GetKartTeam(player_name) != KART_TEAM_NONE;
}



